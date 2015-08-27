#ifndef BUW_LIGHT_HPP
#define BUW_LIGHT_HPP

#include <glm/glm.hpp>
#include "color.hpp"


class Light
{
public:
	Light(std::string name, glm::vec3 const & location, Color const& la, Color const& ld);
	std::string getName() const;
	Color getLa() const;
	Color getLd() const;
	glm::vec3 getLocation() const;

private:
	std::string name_;
	glm::vec3 location_;
	Color la_;
	Color ld_;
};
#endif