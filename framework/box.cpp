#define GLM_FORCE_RADIANS
#include "box.hpp"



//Constructor
Box::Box(): Shape{}, _max{1.0f}, _min{0.0f}
{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max):Shape{},_min{min}, _max{max}
{}

Box::Box(std::string name , std::shared_ptr<Material> material, glm::vec3 const& min, glm::vec3 const& max):Shape(name, material),  _min{max}, _max{min}
{}

Box::~Box()
{}

glm::vec3 Box::min() const
{
	return _min;
}

glm::vec3 Box::max() const
{
	return _max;
}

double Box::volume() const
{
	glm::vec3 vec = _max - _min;

	return fabs(vec.x * vec.y * vec.z);
}

double Box::area() const
{	
	glm::vec3 vec = _max - _min;

	return 2*fabs((vec.x * vec.y) + (vec.x * vec.z) + (vec.y * vec.z));
}

std::ostream& Box::print(std::ostream& os) const
{
	os << "[Box: " << _name << "]\n[Matierial: " << _material << "]\n[Min: " << _min.x << "," << _min.y << "," << _min.z << "]\n[Max: " << _max.x << "," << _max.y << "," << _max.z << "]\n";
	return os;
}



bool Box::intersect(Ray const& r, float& d) const
{
	//Calculate intersection distances of x edges
	double tx1 = (_min.x - r.origin_.x)/glm::normalize(r.direction_).x;
	double tx2 = (_max.x - r.origin_.x)/glm::normalize(r.direction_).x;
	
	double tnear = std::min(tx1, tx2);
	double tfar = std::max(tx1, tx2);
	
	//Calculate intersection distances of y edges
	double ty1 = (_min.y - r.origin_.y)/glm::normalize(r.direction_).y;
	double ty2 = (_max.y - r.origin_.y)/glm::normalize(r.direction_).y;
	
	tnear = std::max(tnear, std::min(ty1, ty2));
	tfar = std::min(tfar, std::max(ty1, ty2));
	
	//Calculate intersection distance of z edges
	double tz1 = (_min.z - r.origin_.z)/glm::normalize(r.direction_).z;
	double tz2 = (_max.z - r.origin_.z)/glm::normalize(r.direction_).z;
	
	tnear = std::max(tnear, std::min(tz1, tz2));
	tfar = std::min(tfar, std::max(tz1, tz2));
	
	return tfar >= std::max(0.0, tnear);
}