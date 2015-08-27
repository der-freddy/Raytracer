#ifndef BUW_HIT_HPP
#define BUW_HIT_HPP

#include <glm/vec3.hpp>
#include "ray.hpp"
#include <memory>

class Shape;

struct Hit
{
	Hit();
	Hit(bool hit, double distance, glm::vec3 const& intersect, glm::vec3 normal_,
	std::shared_ptr<Shape> shape);

	glm::vec3 getIntersect() const;

	bool hit_;
	double distance_;
	glm::vec3 intersect_;
	glm::vec3 normal_;
	std::shared_ptr<Shape> shape_;
};

#endif
