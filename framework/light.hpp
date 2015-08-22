#ifndef BUW_LIGHT_HPP
#define BUW_LIGHT_HPP

#include <glm/glm.hpp>
#include "color.hpp"


class Light
{
public:
	Light(glm::vec3 const & loc, Color const& col, std::string name);
	std::string getName() const;
	Color getColor() const;
	glm::vec3 getLocation() const;

private:
	glm::vec3 location_;
	Color color_;
	std::string name_;
};
#endif