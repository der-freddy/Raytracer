#include "light.hpp"

Light::Light(std::string name, glm::vec3 const& location, Color const& color):
name_{name},
location_{location},
color_{color}
{};

std::string Light::getName() const
{
	return name_;
}

Color Light::getColor() const
{
	return color_;
}

glm::vec3 Light::getLocation() const
{
	return location_;
}