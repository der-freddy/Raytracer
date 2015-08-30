#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include <string>
#include <stdlib.h>
#include <glm/vec3.hpp>
#include "shape.hpp"
#include "hit.hpp"


class Sphere : public Shape
{	
	public:
	//Constructor
		Sphere();
		~Sphere();
		Sphere(glm::vec3 const& mp, double r);
		Sphere(std::string name, std::shared_ptr<Material> material, glm::vec3 const& mp, double r);

		glm::vec3 mp() const;

		double radius() const;

		std::ostream& print(std::ostream& os) const override;

		Hit intersect(Ray const& ray) const override;

	private:
		glm::vec3 _mp;
		double _r;
};

#endif // BUW_SPHERE_HPP
