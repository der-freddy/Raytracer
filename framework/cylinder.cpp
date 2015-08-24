#define GLM_FORCE_RADIANS
#include "cylinder.hpp"



//Constructor
Cylinder::Cylinder():
Shape{},
mp_{0.0f},
r_{1.0f},
height_{1.0f}
{}

Cylinder::Cylinder(glm::vec3 const& mp, float const& r, float const& height):
Shape{},
mp_{mp},
r_{r},
height_{height}
{}

Cylinder::Cylinder(std::string name , std::shared_ptr<Material> material, glm::vec3 const& mp, float const& r, float const& height):
Shape{name, material},
mp_{mp},
r_{r},
height_{height}
{}

Cylinder::~Cylinder()
{}

double Cylinder::volume() const
{
	return (M_PI*r_*r_)*height_;
}

double Cylinder::area() const
{
	float cf = 2*M_PI*r_;
	return 2*(M_PI*r_*r_)+cf;
}
