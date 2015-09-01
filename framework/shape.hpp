#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#define GLM_FORCE_RADIANS
#include "material.hpp"
#include <string>
#include "ray.hpp"
#include <iostream>
#include <memory>
#include "hit.hpp"
#include <map>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform.hpp>

class Shape
{
public:

	//Constructor
	Shape();
	Shape(std::string name, std::shared_ptr<Material> material);
	Shape(std::string name);
	//Destructor
	virtual ~Shape();
	virtual Hit intersect(Ray const&) const = 0; 
	std::shared_ptr<Material> material() const;
	Color ka() const;
	Color kd() const;
	Color ks() const;
	std::string name() const;
	virtual std::ostream& print(std::ostream& os) const;

	void translate(glm::vec3);
	void rotate(glm::vec3);
	void scale(glm::vec3);

protected:
	std::string _name;
	std::shared_ptr<Material> _material;
	glm::mat4 world_transformation_;
	glm::mat4 world_transformation_inv_;

};

std::ostream& operator<<(std::ostream& os , Shape const& s);

#endif // BUW_SHAPE_HPP