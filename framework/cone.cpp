#define GLM_FORCE_RADIANS
#include "cone.hpp"



//Constructor
Cone::Cone():
Shape{},
mp_{0.0f},
r_{1.0f},
height_{1.0f}
{}

Cone::Cone(std::string const& name , std::shared_ptr<Material> const& material, glm::vec3 const& mp, float r, float  height):
Shape{name, material},
r_{r},
height_{height}
{}

Cone::~Cone()
{}
