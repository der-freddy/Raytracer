#ifndef BUW_SCENE_HPP
#define BUW_SCENE_HPP
#include <map>
#include <shape.hpp>
#include <sphere.hpp>
#include <box.hpp>
#include <material.hpp>
#include <camera.hpp>
#include <string>

class Scene
{
public:
	//Constructor
	Scene();
 	~Scene();


 	void addShape(std::string, std::shared_ptr<Shape>);

 	void addMaterial(srd::string, std::shared_ptr<Material>);

 	void addCam(std::string, std::shared_ptr<Camera>);

private:
  std::map<std::string, Material> materials;
  std::map<std::string, Shapes> spheres;
  std::shared_ptr<Camera> cam{};

};

#endif