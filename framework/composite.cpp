#include "composite.hpp"

Composite::Composite(std::string name):
Shape(name),
shapes_()
{}

Composite::~Composite():
{}

void Composite::addShape(std::shared_ptr<Shape> s)
{
	shapes_[s -> name()] = s;
}

std::shared_ptr<Shape> Composite::getShapes()
{
	return shapes_;
}
std::shared_ptr<Shape> Composite::getShape(std::string name);
{
	return 0;
}