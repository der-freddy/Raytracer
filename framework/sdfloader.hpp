#ifndef BUW_SDF_HPP
#define BUW_SDF_HPP
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <material.hpp>
#include <scene.hpp>
#include <box.hpp>
#include <sphere.hpp>
#include <camera.hpp>
#include <light.hpp>

class Sdfloader
{
public:
	//Constructor
	Sdfloader();
	Sdfloader(std::string path, std::string file);
	~Sdfloader();

	Scene const& scene() const;

	void readSdf(std::string path);
	//void create_composite(std::istringstream&);
	void create_material(std::istringstream&);
	void create_sphere(std::istringstream&);
	void create_box(std::istringstream&);
	void create_cam(std::istringstream&);
	void create_light(std::istringstream&);

private:
		Scene scene_;
};


#endif // BUW_SDF_HPP