#include "light.hpp"

Light::Light(std::string name, glm::vec3 const& location, Color const& la, Color const& ld):
name_{name},
location_{location},
la_{la},
ld_{ld}
{};

std::string Light::getName() const
{
	return name_;
}

Color Light::getLa() const
{
	return la_;
}

Color Light::getLd() const
{
	return ld_;
}

glm::vec3 Light::getLocation() const
{
	return location_;
}