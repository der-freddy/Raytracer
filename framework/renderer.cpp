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
<<<<<<< HEAD
    glm::vec3 L = (i->second->getLocation() - hit.getIntersect());
    glm::vec3 N = (hit.normal_);

    float dot = glm::dot(L, N);
    if(dot > 0)
    {
      diff += (i->second->getLd() * hit.shape_->material()->m() * dot);
    }
=======
    std::cout << "test1" << std::endl;
    float a = (glm::dot(i->second->getLocation()-hit.getIntersect(), hit.normal_));
    std::cout << "test2" << std::endl;
    Color diffTemp {a ,a ,a};
    std::cout << "test3" << std::endl;
    diffTemp += diffTemp*diff;
    // diffTemp += diffTemp*(i->second->getLd())*(hit.shape_->material()->kd());
    std::cout << "test4" << std::endl;
    diff += diffTemp;
>>>>>>> c93e590d22a956e93a842fb2d9247828e64f3ac1
  }
  return diff;
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

Color Renderer::raytrace(Ray const& ray, Color color, int depth)
{
  float d = 1.0f;
  Color ambient(0.0, 0.0, 0.0);

  Hit intersection{closestIntersection(ray)};

  if(intersection.hit_)
  {
    ambient = (getDiffuse(intersection)*intersection.shape_->material()->kd()) + ((intersection.shape_->material()->ka() * scene_->globalAmbient_));
  }
  return ambient;
} 
