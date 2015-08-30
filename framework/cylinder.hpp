#ifndef BUW_CYLINDER_HPP
#define BUW_CYLINDER_HPP
#include <glm/vec3.hpp>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "shape.hpp"
#include "ray.hpp"



class Cylinder : public Shape
{	
	public:
	//Constructor
	Cylinder();
	Cylinder(glm::vec3 const& mp, float const& r, float const& height);
	Cylinder(std::string name, std::shared_ptr<Material> material, glm::vec3 const& mp, float const& r, float const& height);
	~Cylinder();
	
	glm::vec3 mp() const;

	glm::vec3 radius() const;

	bool intersectCylinder(Ray const&) const; 

	private:
		glm::vec3 mp_;
		float r_;
		float height_;
};

#endif // BUW_CYLINDER_HPP
