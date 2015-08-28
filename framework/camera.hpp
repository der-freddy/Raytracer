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
	double getFov_x() const;
	glm::vec3 getEye() const;
	glm::vec3 getDir() const;
	glm::vec3 getUp() const;//everybody



	std::string name_;
	double fov_x_;
	glm::vec3 eye_;
	glm::vec3 dir_;
	glm::vec3 up_;
};

#endif