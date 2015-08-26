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



 Hit Box::intersect(Ray const& r) const
 {
    double t1 = (_min.x - r.origin_.x)/glm::normalize(r.direction_).x;
    double t2 = (_max.x - r.origin_.x)/glm::normalize(r.direction_).x;
    double tmin = std::min(t1, t2);
    double tmax = std::max(t1, t2);

    t1 = (_min.y - r.origin_.y)/glm::normalize(r.direction_).y;
    t2 = (_max.y - r.origin_.y)/glm::normalize(r.direction_).y;
    tmin = std::max(tmin, std::min(t1, t2));
    tmax = std::min(tmax, std::max(t1, t2));

    t1 = (_min.z - r.origin_.z)/glm::normalize(r.direction_).z;
    t2 = (_max.z - r.origin_.z)/glm::normalize(r.direction_).z;
    tmin = std::max(tmin, std::min(t1, t2));
    tmax = std::min(tmax, std::max(t1, t2));

    Hit intersec{};

    if (tmax > std::max(0.0, tmin)) {
        intersec.distance_ = sqrt(
            tmin*tmin*(
                r.direction_.x*r.direction_.x +
                r.direction_.y*r.direction_.y +
                r.direction_.z*r.direction_.z
            )
        );

        intersec.intersect_ = glm::vec3{
            tmin*r.direction_.x, tmin*r.direction_.y, tmin*r.direction_.z
        };
        intersec.normal_ = normal(intersec.intersect_);
        intersec.shape_ = std::make_shared<Box>(*this);
        intersec.hit_ = true;
    }

    return intersec;
}

glm::vec3 Box::normal(glm::vec3 const& insec) const {

    glm::vec3 normal{ INFINITY, INFINITY, INFINITY };
    const double epsilon = 5.97e-5;

    if (abs(_min.x - insec.x) < epsilon) {
        normal = glm::vec3{ -1.0, 0.0, 0.0 };
    } else if (abs(_min.y - insec.y) < epsilon) {
        normal = glm::vec3{ 0.0, -1.0, 0.0 };
    } else if (abs(_min.z - insec.z) < epsilon) {
        normal = glm::vec3{ 0.0, 0.0, 1.0 };
    } else if (abs(_max.x - insec.x) < epsilon) {
        normal = glm::vec3{ 1.0, 0.0, 0.0 };
    } else if (abs(_max.y - insec.y) < epsilon) {
        normal = glm::vec3{ 0.0, 1.0, 0.0 };
    } else if (abs(_max.z - insec.z) < epsilon) {
        normal = glm::vec3{ 0.0, 0.0, -1.0 };
    }

    return  normal;
}