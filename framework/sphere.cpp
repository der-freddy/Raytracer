#define GLM_FORCE_RADIANS
#include "shape.hpp"
#include "sphere.hpp"
#include <cmath>
#include "glm/ext.hpp"

//Constructor
Sphere::Sphere(): Shape{}, _mp{0.0f}, _r{0.0f}
{}
Sphere::Sphere(glm::vec3 const& mp, double r): Shape{}, _mp{mp}, _r{r}
{}

Sphere::Sphere(std::string name, Material* material, glm::vec3 const& mp, double r): Shape(name, material), _mp{mp}, _r{r} 
{
	//std::cout << _name << "(Sphere) created\n";
}

Sphere::~Sphere()
{
	//std::cout << _name << "(Sphere) destroyed\n";
}

glm::vec3 Sphere::mp() const
{
	return _mp;
}
double Sphere::radius() const
{
	return _r;
}
double Sphere::volume() const
{
	return (4.0/3.0)*M_PI*_r*_r*_r;
}
double Sphere::area() const
{
	return 4.0*M_PI*_r*_r;
}

std::ostream& Sphere::print(std::ostream& os) const
{
	os << "[Sphere: " << _name << "]\n[Material: " << _material << "]\n[Point: " << glm::to_string(_mp) << "]\n[radius: " << _r << "]\n";
	return os;
}

bool Sphere::intersect(Ray const& ray, float& d) const
{
	return glm::intersectRaySphere(ray.origin_, glm::normalize(ray.direction_),_mp, _r, d);
}
