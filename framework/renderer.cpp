// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include "renderer.hpp"

Renderer::Renderer(unsigned w, unsigned h, std::string const& file, std::shared_ptr<Scene> scene)
  : width_(w)
  , height_(h)
  , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)
  , scene_(scene)
  , fovDistance_(-(0.5 * width_ / std::tan(
        0.5 * scene_->cam_.fov_x_ * M_PI / 180)))
{}

void Renderer::render()
{
  typedef std::map<std::string, std::shared_ptr<Light>>::iterator it_type;

  for(it_type i = scene_->lights_.begin(); i != scene_->lights_.end(); i++)
  {
    scene_->globalAmbient_ += i->second->getLa();
  }

  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {

      int x_pos = x - (width_/2);
      int y_pos = y - (height_/2);

      Ray ray{{0.0, 0.0, 0.0}, {x_pos, y_pos, fovDistance_}};
      Pixel p(x,y);
        p.color = raytrace(ray, Color{0.0,0.0,0.0}, 1);
      write(p);
    }
  }
  ppm_.save(filename_);
}

void Renderer::write(Pixel const& p)
{
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (width_*p.y + p.x);
  if (buf_pos >= colorbuffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    colorbuffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}


Color Renderer::ka(std::shared_ptr<Shape> shape) const
{
  return shape->material()->ka();
}

Color Renderer::kd(std::shared_ptr<Shape> shape) const
{
  return shape->material()->kd();
}

Color Renderer::ks(std::shared_ptr<Shape> shape) const
{
  return shape->material()->ks();
}

Color Renderer::getDiffuse(Hit const& hit) const
{
  Color diff{}; 
  typedef std::map<std::string, std::shared_ptr<Light>>::iterator it_type;

  for(it_type i = scene_->lights_.begin(); i != scene_->lights_.end(); i++)
  {
    glm::vec3 L = glm::normalize(i->second->getLocation() - hit.getIntersect());
    glm::vec3 N = (hit.normal_);

    float dot = glm::dot(L, N);
    if(dot > 0)
    {
      //diff += (i->second->getLd() * hit.shape_->material()->m() * dot);
      diff += (i->second->getLd() * hit.shape_->material()->kd() * dot);
    }
  }
  return diff;
}

Color Renderer::getSpecular(Hit const& hit) const
{

  
  Color spec{};
  typedef std::map<std::string, std::shared_ptr<Light>>::iterator it_type;

  for(it_type i = scene_->lights_.begin(); i != scene_->lights_.end(); i++)
  {
      glm::vec3 camVec = glm::normalize(hit.normal_ - scene_->cam_.getEye());

      glm::vec3 lightVec = glm::normalize(hit.normal_ - i->second->getLocation());

      double angle = glm::dot(lightVec, camVec);
      if(angle < 0)
      {
      double value = std::abs(std::pow(angle, hit.shape_->material()->m()));

      spec += hit.shape_->material()->ks() * i->second->getLd() * std::max(value, 0.0);
      }
    }
return spec;
}

bool Renderer::closestIntersection(Hit const& hit, std::shared_ptr<Light> const& light) const 
{
  Ray ray{light->getLocation(),hit.getIntersect() - light->getLocation()};
  Hit hit_temp{hit.shape_->intersect(ray)};
  
  return hit_temp.distance_ >= hit.distance_;

}


Hit Renderer::closestIntersection(Ray const& ray) 
{
  double closest = INFINITY;
  Hit hit{};
  typedef std::map<std::string, std::shared_ptr<Shape>>::iterator it_type;

  for(it_type i = scene_->shapes_.begin(); i != scene_->shapes_.end(); i++)
  {
    Hit hit_temp{i->second->intersect(ray)};

    if(hit_temp.distance_ < closest) 
    {
      closest = hit_temp.distance_;
      hit = hit_temp;
    }
  }
  return hit;
}

Color Renderer::getRefl(Hit const& hit, int depth, Ray const& ray)
{
  int r = hit.shape_->material()->refl();
  Color refl(0.0, 0.0, 0.0);
  if(r > 0.0f)
  {
    glm::vec3 camVec = glm::normalize(ray.direction_);

    glm::vec3 N = glm::normalize(hit.normal_);
    glm::vec3 R = camVec - (2.0f* glm::dot(camVec, N) * N);

    if(depth < 5)
    {

      refl = raytrace(Ray{hit.getIntersect()+ R, R}, refl, ++depth);
      refl += (refl * r) * hit.shape_->material()->ka();
    }
  }

  return refl;
}

Color Renderer::getRefr(Hit const& hit, Ray const& ray, int depth)
{
  // float rindex = hit.shape_->material()->refr();
  // float opacity = hit.shape_->material()->opacity();

  // glm::vec3 camVec = glm::normalize((hit.getIntersect()-ray.origin_));

  // glm::vec3 N = glm::normalize(hit.normal_);
  
  // if(rindex > 0.0f)
  // {
  //   if(glm::dot(glm::dot(N, glm::normalize(ray.direction_)) < 0))
  //   {
  //     float n1 = rindex;
  //     float n2 = 1.0f;
  //     float cos1 = glm::dot(N, -glm::normalize(ray.direction_));
  //   }
  //   else
  //   {
  //     float n1 = 1.0f;
  //     float n2 = rindex;
  //     float cos1 = glm::dot(N, glm::normalize(ray.direction_));
  //   }

  //   float n = n1/n2;

  //   float disc = 1.0f - ((n*n)*(1.0f-(cos1+cos1)));

  // }

float rindex = hit.shape_->material()->refr();

Color refr(0.0, 0.0, 0.0);
 if(rindex > 0.0f)
  {
  Color refr(0.0, 0.0, 0.0);
  
  rindex = (1.0f/rindex);
  float opacity = hit.shape_->material()->opacity();
  glm::vec3 camVec = glm::normalize((hit.getIntersect()-ray.origin_));
  

  glm::vec3 N = glm::normalize(hit.normal_);  
  float cosI = -glm::dot(N, glm::normalize(ray.direction_));
 
 
    
    float cosT2 = 1.0f - rindex * rindex * (1.0f - cosI * cosI);
    std::cout << cosI << std::endl;
    if(cosI < 0)
    {
      glm::vec3 T = ( camVec - 2*-(cosI)*N);
      
      T = T  * float((rindex * rindex * cosI - sqrt(cosT2)));
     
      refr = raytrace(Ray{(hit.getIntersect() + T * 0.1f), (camVec)}, refr, ++depth);
      refr += (refr);      
    }
    else
    {
       glm::vec3 T = (N * camVec - 2*(cosI)*N);
       //glm::vec3 T = ( camVec - 2*-(cosI)*N);
      //glm::vec3 T = ( N * (camVec * rindex));
      //glm::vec3 T = ((camVec - 2*(cosI)*N));
      
      T = T  * float((rindex * rindex * cosI - sqrt(cosT2)));
         
      refr = raytrace(Ray{(hit.getIntersect() + T * 0.1f), T}, refr, ++depth);
      refr += (refr);
    }
    return refr*0.5;
  }
  else
  {
    return refr;

  }



  // if((rindex > 0) && (depth < 5))
  // {

  //   glm::vec3 N = glm::normalize(hit.normal_);
  //   float n = 1.0f / rindex;
  //   float cosI = -glm::dot(N, glm::normalize(ray.direction_));
  //   float cosT2 = 1.0f - rindex * rindex * (1.0f - cosI * cosI);

  //   if(cosT2 > 0.0f)
  //   {
  //     glm::vec3 T = ( N * (ray.direction_ * rindex));
  //     T = T  * float((rindex * rindex * cosI - sqrt(cosT2)));
  //     Color refr(0.0,0.0,0.0);
  //     refr = raytrace(Ray{hit.getIntersect()+ T, T}, refr, ++depth);
  //     refr += refr;

  //   }
  // }
  // return refr;
}

Color Renderer::raytrace(Ray const& ray, Color color, int depth)
{
  float d = 1.0f;
  Color ambient(0.0, 0.0, 0.0);

  Hit intersection{closestIntersection(ray)};

  if(intersection.hit_)
  {
    ambient = getDiffuse(intersection) + getSpecular(intersection) + ((intersection.shape_->material()->ka() * scene_->globalAmbient_)) + (getRefl(intersection, depth, ray)) + (getRefr(intersection,ray,depth));
  }
  return ambient;
} 
