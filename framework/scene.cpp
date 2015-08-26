#include <scene.hpp>

Scene::Scene():
shapes_(),
cam_(),
materials_(),
lights_(),
composites_()
{}

Scene::~Scene()
{}

void Scene::addShape(std::string name, std::shared_ptr<Shape> shape)
{
	shapes_[name] = shape;
}

void Scene::addMaterial(std::string name, Material ma)
{
	materials_[name] = std::make_shared<Material>(ma);
}

void Scene::addCam(Camera camera)
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
	//else return Material{};
}

std::map<std::string, std::shared_ptr<Material>> Scene::material() const
{
	return materials_;
}

void Scene::addLight(std::string name, std::shared_ptr<Light> light)
{
	lights_[name] = light;
}

std::shared_ptr<Composite> Scene::getComposites() const
{
	return composites_;
}

std::shared_ptr<Shape> Scene::getShape(std::string const& name) const
{

	auto i = shapes_.find(name);
	
	if( i != shapes_.end())
	{

		return i -> second;
		std::cout << name << std::endl;
	}
}
// std::ostream& operator<<(std::ostream& output, Scene const& scene)
// {
    // for(auto i : scene.materials)
        // output << i.second << std::endl << std::endl;
    // return output;
// }