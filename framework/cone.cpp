#define GLM_FORCE_RADIANS
#include "cone.hpp"



//Constructor
Cone::Cone():
Shape{},
mp_{0.0f},
r_{1.0f},
height_{1.0f}
{}

Cone::Cone(std::string name , std::shared_ptr<Material> material, glm::vec3 const& mp, float const& r, float const& height):
Shape{name, material},
r_{r},
height_{height}
{}

Cone::~Cone()
{}

double Cone::volume() const
{
	return (M_PI/3)*r_*r_*height_;
}

double Cone::area() const
{
	float s = sqrt((height_*height_)+(r_*r_));
	return M_PI*r_*(r_+s); 
}
