#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
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
	Box();
	Box(glm::vec3 const& min, glm::vec3 const& max);
	Box(std::string name, Material* material, glm::vec3 const& min, glm::vec3 const& max);
	~Box();
	glm::vec3 max() const;

	glm::vec3 min() const;

	double volume() const override;

	double area() const override;

	std::ostream& print(std::ostream & os) const override;

	bool intersectBox(Ray const&) const; 

	private:
		glm::vec3 _max;
		glm::vec3 _min;
};

#endif // BUW_BOX_HPP
