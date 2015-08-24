#include <scene.hpp>

Scene::Scene():
shapes_(),
cam_(),
materials_(),
lights_()
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

void Scene::addCam(std::shared_ptr<Camera> camera)
{
	cam_ = camera;
}

std::shared_ptr<Material> Scene::getMaterial(std::string name) const
{
	auto i = materials_.find(name);
	if (i != materials_.end()) {
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
// std::ostream& operator<<(std::ostream& output, Scene const& scene)
// {
    // for(auto i : scene.materials)
        // output << i.second << std::endl << std::endl;
    // return output;
// }