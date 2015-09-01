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
	Box(std::string const& name, std::shared_ptr<Material> const& material, glm::vec3 const& min, glm::vec3 const& max);
	~Box();
	glm::vec3 max() const;

	glm::vec3 min() const;

	std::ostream& print(std::ostream & os) const override;

	Hit intersect(Ray const&) const override; 

	glm::vec3 normal(glm::vec3 const&) const;

	private:
		glm::vec3 _max;
		glm::vec3 _min;
};

#endif // BUW_BOX_HPP
