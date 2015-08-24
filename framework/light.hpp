#ifndef BUW_LIGHT_HPP
#define BUW_LIGHT_HPP

#include <glm/glm.hpp>
#include "color.hpp"


class Light
{
public:
	Light(std::string name, glm::vec3 const & location, Color const& col);
	std::string getName() const;
	Color getColor() const;
	glm::vec3 getLocation() const;

private:
	std::string name_;
	glm::vec3 location_;
	Color color_;
};
#endif