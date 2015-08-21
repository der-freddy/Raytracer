#ifndef BUW_CONE_HPP
#define BUW_CONE_HPP
#include <glm/vec3.hpp>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "shape.hpp"
#include "ray.hpp"



class Box : public Shape
{	
	public:
	//Constructor
	Cone();
	Cone(glm::vec3 const&, float, float);
	Cone(std::string name, Material* material, glm::vec3 const&, float, float);
	~Cone();
	glm::vec3 mp() const;

	glm::vec3 radius() const;

	double volume() const override;

	double area() const override;

	bool intersectCone(Ray const&) const; 

	private:
		glm::vec3 mp_;
		float r_;
		float height_;
};

#endif // BUW_CONE_HPP