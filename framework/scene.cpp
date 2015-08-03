#include <scene.hpp>

Scene::Scene():
spheres(),
boxes(),
cam(),
materials()
{}

Scene::~Scene()
{}

std::ostream& operator<<(std::ostream& output, Scene const& scene)
{
    for(auto i : scene.materials)
        output << i.second << std::endl << std::endl;
    return output;
}