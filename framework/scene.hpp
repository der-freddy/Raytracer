#ifndef BUW_SCENE_HPP
#define BUW_SCENE_HPP
#include <map>
#include <shape.hpp>
#include <sphere.hpp>
#include <box.hpp>
#include <material.hpp>
#include <camera.hpp>
#include <string>

struct Scene 
{
  Scene();
  ~Scene();

  std::map<std::string, Material> materials;
  std::map<std::string, Box> boxes;
  std::map<std::string, Sphere> spheres;
  Camera cam{};


};


#endif