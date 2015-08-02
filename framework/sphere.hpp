#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include <string>
#include <stdlib.h>
#include <glm/vec3.hpp>
#include "shape.hpp"



class Sphere : public Shape
{	
	public:
	//Constructor
		Sphere();
		~Sphere();
		Sphere(glm::vec3 const& mp, double r);
		Sphere(std::string name, Material const& material, glm::vec3 const& mp, double r);

		glm::vec3 mp() const;

		double radius() const;

		double area() const override;

		double volume() const override;

		std::ostream& print(std::ostream& os) const override;

		bool intersect(Ray const& ray, float& d) const;

	private:
		glm::vec3 _mp;
		double _r;
};

#endif // BUW_SPHERE_HPP
