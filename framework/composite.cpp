#include "composite.hpp"

Composite::Composite(std::string name):
Shape{name},
shapes_{}
{}

Composite::~Composite()
{}

void Composite::addShape(std::shared_ptr<Shape> s)
{
	shapes_[s -> name()] = s;
}

double Composite::volume() const
{
	return 0;
}
double Composite::area() const
{
	return 0;
}
Hit Composite::intersect(Ray const& ray) const
{
	return;
}

std::shared_ptr<Shape> Composite::getShape(std::string name)
{
	auto i = shapes_.find(name);
	if (i != shapes_.end())
	{
		return i -> second;
	}
}


std::map<std::string, std::shared_ptr<Shape>> Composite::getShapes()
{
	return shapes_;
}

// std::shared_ptr<Shape> Composite::getShape(std::string name);
// {
	
// }