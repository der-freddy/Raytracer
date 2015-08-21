#define GLM_FORCE_RADIANS
#include "cone.hpp"



//Constructor
Cone::Cone(): Shape{}, mp_{1.0f}, r_{1.0f}, height_{1.0f}
{}

Cone::Cone(glm::vec3 const& mp, float const& r, float const& height):Shape{}, mp_{mp}, r_{r}, height_{height}
{}

Cone::Cone(std::string name , Material* material, glm::vec3 const& mp, float const& r, float const& height):Shape(name, material), mp_{mp}, r_{r}, height_{height}
{}

Cone::~Cone()
{}

