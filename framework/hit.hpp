#ifndef BUW_HIT_HPP
#define BUW_HIT_HPP

#include <glm/vec3.hpp>
#include "ray.hpp"
#include <memory>
#include "shape.hpp"

struct Hit
{
	Hit();
	Hit(bool hit, double distance, glm::vec3 const& intersect, 
	std::shared_ptr<Shape> shape);

	bool hit_;
	double distance_;
	glm::vec3 intersect_;
	std::shared_ptr<Shape> shape_;
};

#endif
