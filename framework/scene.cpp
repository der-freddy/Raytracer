#include <scene.hpp>

Scene::Scene():
shapes_(),
cam_(),
materials_()
{}

Scene::~Scene()
{}

void Scene::addShape(std::string name, std::shared_ptr<Shape> shape)
{
	shapes_[name] = shape;
}

void Scene::addMaterial(std::string name, Material ma)
{
	materials_[name] = ma;
}

void Scene::addCam(std::shared_ptr<Camera> camera)
{
	cam_ = camera;
}

Material Scene::getMaterial(std::string name)
{
	auto i = materials_.find(name);
	if (i != materials_.end()) {
		return i -> second;
	}
	else return Material{};
}
// std::ostream& operator<<(std::ostream& output, Scene const& scene)
// {
    // for(auto i : scene.materials)
        // output << i.second << std::endl << std::endl;
    // return output;
// }