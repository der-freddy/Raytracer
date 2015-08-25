#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include "material.hpp"
#include <string>
#include "ray.hpp"
#include <iostream>
#include <memory>

class Shape
{
public:

	//Constructor
	Shape();
	Shape(std::string name, std::shared_ptr<Material> material);
	Shape(std::string name);
	//Destructor
	virtual ~Shape();
	
	virtual double area() const = 0;

	virtual double volume() const = 0;

	virtual bool intersect(Ray const&, float& d) const = 0; 

	std::shared_ptr<Material> material() const;

	std::string name() const;

	virtual std::ostream& print(std::ostream& os) const;

private:

protected:
	std::string _name;
	std::shared_ptr<Material> _material;

};

std::ostream& operator<<(std::ostream& os , Shape const& s);

#endif // BUW_SHAPE_HPP