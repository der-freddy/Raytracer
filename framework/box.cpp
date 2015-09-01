#define GLM_FORCE_RADIANS
#include "box.hpp"



//Constructor
Box::Box(): Shape{}, _max{1.0f}, _min{0.0f}
{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max):Shape{},_min{min}, _max{max}
{}

Box::Box(std::string const& name , std::shared_ptr<Material> const& material, glm::vec3 const& min, glm::vec3 const& max):Shape(name, material),  _min{min}, _max{max}
{}

Box::~Box()
{}

glm::vec3 Box::min() const
{
	return _min;
}

glm::vec3 Box::max() const
{
	return _max;
}

std::ostream& Box::print(std::ostream& os) const
{
	os << "[Box: " << _name << "]\n[Matierial: " << _material << "]\n[Min: " << _min.x << "," << _min.y << "," << _min.z << "]\n[Max: " << _max.x << "," << _max.y << "," << _max.z << "]\n";
	return os;
}



 Hit Box::intersect(Ray const& r) const
 {
    double t1 = (_min.x - r.origin_.x)/glm::normalize(r.direction_).x;
    double t2 = (_max.x - r.origin_.x)/glm::normalize(r.direction_).x;
    double tmin = std::min(t1, t2);
    double tmax = std::max(t1, t2);

    t1 = (_min.y - r.origin_.y)/glm::normalize(r.direction_).y;
    t2 = (_max.y - r.origin_.y)/glm::normalize(r.direction_).y;
    tmin = std::max(tmin, std::min(t1, t2));
    tmax = std::min(tmax, std::max(t1, t2));

    t1 = (_min.z - r.origin_.z)/glm::normalize(r.direction_).z;
    t2 = (_max.z - r.origin_.z)/glm::normalize(r.direction_).z;
    tmin = std::max(tmin, std::min(t1, t2));
    tmax = std::min(tmax, std::max(t1, t2));

    Hit intersec{};

    if (tmax > std::max(0.0, tmin)) {

      intersec.distance_ = tmin;
      // sqrt(
      // (
      //  intersec.intersect_.x* intersec.intersect_.x +
      //  intersec.intersect_.y* intersec.intersect_.y +
      //  intersec.intersect_.z* intersec.intersect_      // );
      intersec.intersect_ = glm::vec3{
          intersec.distance_*glm::normalize(r.direction_).x, intersec.distance_ * glm::normalize(r.direction_).y, intersec.distance_ * glm::normalize(r.direction_).z
      };
      intersec.normal_ = normal(intersec.intersect_);
      intersec.shape_ = std::make_shared<Box>(*this);
      intersec.hit_ = true;
    }
    //std::cout << intersec.intersect_.z << std::endl;
    return intersec;
}

glm::vec3 Box::normal(glm::vec3 const& intersection) const
{
  glm::vec3 front{0.0, 0.0, 1.0};
  glm::vec3 right{1.0, 0.0, 0.0};
  glm::vec3 back{0.0, 0.0, -1.0};
  glm::vec3 left{-1.0, 0.0, 0.0};
  glm::vec3 top{0.0, 1.0, 0.0};
  glm::vec3 down{0.0, -1.0, 0.0};

  std::map<float, glm::vec3> dotMin;

  dotMin.insert(std::make_pair((glm::dot(front,(intersection-_min))), front));
  dotMin.insert(std::make_pair((glm::dot(left,(intersection-_min))), left));
  dotMin.insert(std::make_pair((glm::dot(down,(intersection-_min))), down));
  dotMin.insert(std::make_pair((glm::dot(top,(intersection-_max))), top));
  dotMin.insert(std::make_pair((glm::dot(right,(intersection-_max))), right));
  dotMin.insert(std::make_pair((glm::dot(back,(intersection-_max))), back));

  float closest = INFINITY;
  glm::vec3 closestTemp{};
  
  for(auto dot : dotMin)
  {
    if(dot.first < closest) 
    {
      closestTemp = dot.second;
    }
  }
  return closestTemp;   
}