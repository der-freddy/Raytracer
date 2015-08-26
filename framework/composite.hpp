#ifndef BUW_COMPOSITE_HPP
#define BUW_COMPOSITE_HPP

#include <memory>
#include <map>
#include <shape.hpp>
#include <box.hpp>
#include <sphere.hpp>
#include <string>


class Composite: public Shape
{
public:
	Composite(std::string name);
	~Composite();
	void addShape(std::shared_ptr<Shape> s);
	double area() const override;
	double volume() const override;
	Hit intersect(Ray const& ray) const override;
	std::shared_ptr<Shape> getShape(std::string name);
	std::map<std::string, std::shared_ptr<Shape>> getShapes();

private:
	std::map<std::string, std::shared_ptr<Shape>> shapes_;
};

#endif