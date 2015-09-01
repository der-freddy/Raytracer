#include <scene.hpp>

Scene::Scene():
shapes_(),
cam_(),
materials_(),
lights_(),
globalAmbient_()
{}

Scene::~Scene()
{}

void Scene::addShape(std::string const& name, std::shared_ptr<Shape> const& shape)
{
	shapes_.insert(std::make_pair(shape->name(),shape));
}

void Scene::addMaterial(std::string const& name, Material const& ma)
{
	materials_[name] = std::make_shared<Material>(ma);
}

void Scene::addCam(Camera const& camera)
{
	cam_ = camera;
}

void Scene::printScene()
{
	std::cout << "scene" << std::endl;
}

std::shared_ptr<Material> Scene::getMaterial(std::string const& name) const
{
	auto i = materials_.find(name);
	if (i != materials_.end())
	{
		return i -> second;
	}
}

std::map<std::string, std::shared_ptr<Material>> Scene::material() const
{
	return materials_;
}

void Scene::addLight(std::string const& name, std::shared_ptr<Light> const& light)
{
	lights_.insert(std::make_pair(light->getName(),light));
}	

std::shared_ptr<Shape> Scene::getShape(std::string const& name)
{
	auto i = shapes_.find(name);
	
	if( i != shapes_.end())
	{
		return i -> second;
		std::cout << name << std::endl;
	}
}

Camera Scene::getCam() const
{
	return cam_;
}

void Scene::addAmbient(Color const& c)
{
	globalAmbient_ += c;
}