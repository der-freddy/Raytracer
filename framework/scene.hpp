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

struct Scene
{
public:
	//Constructor
	Scene();
 	~Scene();

	void printScene();

 	void addShape(std::string const&, std::shared_ptr<Shape> const&);

 	void addMaterial(std::string const&, Material const&);

 	void addCam(Camera const&);

 	void addLight(std::string const&, std::shared_ptr<Light> const&);

 	void addAmbient(Color const& c);

 	std::shared_ptr<Material> getMaterial(std::string const& name) const;

 	std::map<std::string, std::shared_ptr<Material>> material() const;

 	std::shared_ptr<Shape> getShape(std::string const& name);

 	Camera getCam() const;

  std::map<std::string, std::shared_ptr<Material>> materials_;
  std::map<std::string, std::shared_ptr<Shape>> shapes_;
  Camera cam_;
  Color globalAmbient_;
  std::map<std::string, std::shared_ptr<Light>> lights_;
};

#endif