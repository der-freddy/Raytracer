#ifndef BUW_SCENE_HPP
#define BUW_SCENE_HPP
#include <map>
#include <shape.hpp>
#include <sphere.hpp>
#include <box.hpp>
#include <material.hpp>
#include <camera.hpp>
#include <string>
#include <tr1/memory>

class Scene
{
public:
	//Constructor
	Scene();
 	~Scene();


 	void addShape(std::string, std::shared_ptr<Shape>);

 	void addMaterial(std::string, Material*);

 	void addCam(std::shared_ptr<Camera>);

 	Material* getMaterial(std::string);

private:
  std::map<std::string, Material*> materials_;
  std::map<std::string, std::shared_ptr<Shape>> shapes_;
  std::shared_ptr<Camera> cam_;

};

#endif