#include <scene.hpp>

Scene::Scene():
shapes(),
cam(),
materials()
{}

Scene::~Scene()
{}

Scene::addShape(std::string name, shared_ptr<Shape> shape)
{
	shapes[name] = shape;
}

addMaterial(str::string name, shared_ptr<material> ma)
{
	materials[name] = ma;
}

Scene::addCam(std::shared_ptr<material> camera)
{
	Cam = camera;
}
// std::ostream& operator<<(std::ostream& output, Scene const& scene)
// {
    // for(auto i : scene.materials)
        // output << i.second << std::endl << std::endl;
    // return output;
// }