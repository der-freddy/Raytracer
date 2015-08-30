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

Sphere::Sphere(std::string name, std::shared_ptr<Material> material, glm::vec3 const& mp, double r): Shape(name, material), _mp{mp}, _r{r} 
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

std::ostream& Sphere::print(std::ostream& os) const
{
	os << "[Sphere: " << _name << "]\n[Material: " << _material << "]\n[Point: " << glm::to_string(_mp) << "]\n[radius: " << _r << "]\n";
	return os;
}

Hit Sphere::intersect(Ray const& ray) const
{
	Hit intersec{};

	intersec.hit_ = glm::intersectRaySphere(ray.origin_, glm::normalize(ray.direction_),_mp, _r, intersec.intersect_, intersec.normal_);

	if(intersec.hit_)
	{
		intersec.distance_ = glm::distance(ray.origin_, intersec.intersect_);
	}

	intersec.shape_ = std::make_shared<Sphere>(*this);

	return intersec;
}
