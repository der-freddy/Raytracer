#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <string>
#include <glm/glm.hpp>

class Camera
{

public:

	Camera();
	Camera(std::string name, double fov_x, glm::vec3 eye, glm::vec3 dir, glm::vec3 up);
	~Camera();
	std::string getName() const ;
	double getFov_x();
	glm::vec3 getEye();
	glm::vec3 getDir();
	glm::vec3 getUp();//everybody

private:

	std::string name_;
	double fov_x_;
	glm::vec3 eye_;
	glm::vec3 dir_;
	glm::vec3 up_;
};

#endif