#ifndef BUW_CONE_HPP
#define BUW_CONE_HPP
#include <glm/vec3.hpp>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "shape.hpp"
#include "ray.hpp"



class Cone : public Shape
{	
	public:
	//Constructor
	Cone();
	Cone(std::string const& name, std::shared_ptr<Material> const& material, glm::vec3 const& mp, float r, float height);
	~Cone();
	
	glm::vec3 mp() const;

	glm::vec3 radius() const;

	bool intersectCone(Ray const&) const; 

	private:
		glm::vec3 mp_;
		float r_;
		float height_;
};

#endif // BUW_CONE_HPP
