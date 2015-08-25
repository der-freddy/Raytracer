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
#include <light.hpp>
#include <composite.hpp>

class Scene
{
public:
	//Constructor
	Scene();
 	~Scene();

void printScene();

 	void addShape(std::string, std::shared_ptr<Shape>);

 	void addMaterial(std::string, Material);

 	void addCam(Camera);

 	std::shared_ptr<Material> getMaterial(std::string) const;

 	void addLight(std::string, std::shared_ptr<Light>);

 	std::map<std::string, std::shared_ptr<Material>> material() const;

 	std::shared_ptr<Composite> getComposites() const;

  std::map<std::string, std::shared_ptr<Material>> materials_;
  std::map<std::string, std::shared_ptr<Shape>> shapes_;
  Camera cam_;
  std::map<std::string, std::shared_ptr<Light>> lights_;
  std::shared_ptr<Composite> composites_;

};

#endif