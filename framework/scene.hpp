#ifndef BUW_SCENE_HPP
#define BUW_SCENE_HPP
#include <map>
#include <shape.hpp>
#include <material.hpp>
#include <memory>

class Scene 
{
public:

  Scene();
  ~Scene();
  


private:

  std::map<std::string, Material> materials;
};


#endif