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
	void addShape(std::shared_ptr<Shape> s);
	std::shared_ptr<Shape> getShapes();
	std::shared_ptr<Shape> getShape(std::string name);

private:
	std::map<std::string, std::shared_ptr<Shape>> shapes_;
};

#endif