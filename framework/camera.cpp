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

std::string Camera::getName()
{
	return name_;
}

double Camera::getFov_x()
{
	return fov_x_;
}

glm::vec3 Camera::getEye()
{
	return eye_;
}

glm::vec3 Camera::getDir()
{
	return dir_;
}

glm::vec3 Camera::getUp()//everybody
{
	return up_;
}