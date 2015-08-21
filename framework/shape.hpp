#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include "material.hpp"
#include <string>
#include "ray.hpp"
#include <iostream>

class Shape
{
public:

	//Constructor
	Shape();
	Shape(std::string name, Material const& material);
	//Destructor
	virtual ~Shape();
	
	virtual double area() const = 0;

	virtual double volume() const = 0;

	Material material() const;

	std::string name() const;

	virtual std::ostream& print(std::ostream& os) const;

private:

protected:
	std::string _name;
	Material _material;

};

std::ostream& operator<<(std::ostream& os , Shape const& s);

#endif // BUW_SHAPE_HPP