#include "shape.hpp"


Shape::Shape():_name{"untitled"} ,_material{}
{}

Shape::Shape(std::string name, std::shared_ptr<Material> material): _name{name}, _material{material}
{
	//std::cout << _name << "(Shape) created\n";
}

Shape::~Shape()
{
	//std::cout << _name <<"(Shape) destroyed\n";
}

std::shared_ptr<Material> Shape::material() const
{
	return _material;
}

std::string Shape::name() const
{
	return _name;
}

std::ostream& Shape::print(std::ostream& os) const
{
	os << "Shape:[Name: " << _name << "][Material: " << _material << "]\n";
	return os;
}

std::ostream& operator<<(std::ostream& os , Shape const& s)
{
	return s.print(os);
}
