#include "camera.hpp"

Camera::Camera() :
name_{"cam"},
fov_x_{45},
eye_{0.0, 0.0, 0.0},
dir_{0.0, 0.0, -1.0},
up_{0.0, 1.0, 0.0}
{}

Camera::Camera(std::string name, double fov_x, glm::vec3 eye, glm::vec3 dir, glm::vec3 up) :
name_(name),
fov_x_(fov_x),
eye_(eye),
dir_(dir),
up_(up)
{}

Camera::~Camera()
{}

std::string Camera::getName() const
{
	return name_;
}

double Camera::getFov_x() const
{
	return fov_x_;
}

glm::vec3 Camera::getEye() const
{
	return eye_;
}

glm::vec3 Camera::getDir() const
{
	return dir_;
}

glm::vec3 Camera::getUp() const //everybody
{
	return up_;
}