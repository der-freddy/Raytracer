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
	void addShape(std::shared_ptr<Shape> const& s);
	Hit intersect(Ray const& ray) const override;
	std::shared_ptr<Shape> getShape(std::string const& name) const; 
	std::map<std::string, std::shared_ptr<Shape>> getShapes() const;

private:
	std::map<std::string, std::shared_ptr<Shape>> shapes_;
};

#endif