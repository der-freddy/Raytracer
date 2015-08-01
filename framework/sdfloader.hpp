#ifndef BUW_SDF_HPP
#define BUW_SDF_HPP
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <material.hpp>
#include <scene.hpp>

class Sdfloader
{
public:
	//Constructor
	Sdfloader();
	Sdfloader(std::string path, std::string file);
	~Sdfloader();

	Scene const& scene() const;

	void readSdf(std::string path);

	void create_material(std::istringstream&);

private:
		Scene scene_;
};


#endif // BUW_SDF_HPP