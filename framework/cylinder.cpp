#define GLM_FORCE_RADIANS
#include "cylinder.hpp"



//Constructor
Cylinder::Cylinder():
Shape{},
mp_{0.0f},
r_{1.0f},
height_{1.0f}
{}

Cylinder::Cylinder(glm::vec3 const& mp, float r, float height):
Shape{},
mp_{mp},
r_{r},
height_{height}
{}

Cylinder::Cylinder(std::string name , std::shared_ptr<Material> material, glm::vec3 const& mp, float r, float height):
Shape{name, material},
mp_{mp},
r_{r},
height_{height}
{}

Cylinder::~Cylinder()
{}