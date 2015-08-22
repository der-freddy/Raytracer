#include "light.hpp"

Light::Light(glm::vec3 const& location, Color const& color, std::string name):
location_{loaction},
color_{color},
name_{name}
{};

std::string Light::getName() const
{
	return name_;
}

glm::vec3 Light::getColor() const
{
	return color_;
}

glm::ve3 Light::getLocation() const
{
	return location_;
}