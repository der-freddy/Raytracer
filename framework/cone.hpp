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
<<<<<<< HEAD
	Cone(glm::vec3 const&, float const&, float const&);
	Cone(std::string name, Material const& material, glm::vec3 const&, float const&, float const&);
=======
	Cone(glm::vec3 const& mp, float const& r, float const& height);
	Cone(std::string name, Material const& material, glm::vec3 const& mp, float const& r, float const& height);
>>>>>>> dev_composite
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
