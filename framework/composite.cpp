#include "composite.hpp"

Composite::Composite(std::string name):
Shape{name},
shapes_{}
{}

Composite::~Composite()
{}

//add shape to composite
void Composite::addShape(std::shared_ptr<Shape> const& s)
{
	shapes_[s->name()] = s;
}


Hit Composite::intersect(Ray const& ray) const
{
	float closest = INFINITY;
  Hit hit{};
  for(auto shape : shapes_)
  {
    Hit hit_temp{shape.second->intersect(ray)};

    if(hit_temp.distance_ < closest && hit_temp.distance_>0.001) 
    {
      closest = hit_temp.distance_;
      hit = hit_temp;
    }
  }
  return hit;
}

//find shape in composite
std::shared_ptr<Shape> Composite::getShape(std::string const& name) const
{
	auto i = shapes_.find(name);
	if (i != shapes_.end())
	{
		return i -> second;
	}
}

//returns map
std::map<std::string, std::shared_ptr<Shape>> Composite::getShapes() const
{
	return shapes_;
}

// std::shared_ptr<Shape> Composite::getShape(std::string name);
// {
	
// }