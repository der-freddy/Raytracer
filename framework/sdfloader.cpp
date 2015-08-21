#include <sdfloader.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
Sdfloader::Sdfloader(): scene_{}
{}

Sdfloader::~Sdfloader()
{}

Scene const& Sdfloader::scene() const
{
  return scene_;
}

void Sdfloader::readSdf(std::string path)
{
  std::ifstream file;
  std::string s;

  file.open(path, std::ios::in);

  while(!file.eof())
  {
    getline(file, s);

    std::istringstream iss{s};
    std::string sub;
    iss >> sub; 

    if(sub == "define")
    {
      iss >> sub;

      if(sub == "material")
      {
        create_material(iss);
      }
      else if(sub == "shape")
      {
        iss >> sub;
        
        if(sub == "Sphere")
        {
          create_sphere(iss);
        }
        else if(sub == "Box")
        {
          create_box(iss);
        }
        else if(sub == "composite")
        {
          //create_composite(iss)
        }
      }
      else if(sub == "light")
      {
        //create_light(iss);
      }
      else if(sub == "camera")
      {
        //create_cam(iss);
      }


    }
    else if(sub == "transform")
    {
      //create_transform(iss);
    }

  }
  

}

void Sdfloader::create_material(std::istringstream& iss)
{
  //Material gets name, color for a,d,s and m
  std::string name;
  float r,g,b,m;
  iss >> name >> r >> g >> b;
  Color ka{r,g,b};

  iss >> r >> g >> b;
  Color kd{r,g,b};

  iss >> r >> g >> b;
  Color ks{r,g,b};

  iss >> m;
  
  std::shared_ptr<Material> material = std::make_shared<Material>(Material(name, ka, kd, ks, m));

  return ;
}

void Sdfloader::create_box(std::istringstream& iss)
{
  //box gets name, min-vector, max-vector and name of material
  std::string name, materialName;
  float x,y,z;

  iss >> name >> x >> y >> z;
  glm::vec3 min(x,y,z);

  iss >> x >> y >> z;
  glm::vec3 max(x,y,z);

  iss >> materialName;

  Material* ma = scene.getMaterial(materialName); //get the material and create object

  std::shared_ptr<Box> box = std::make_shared<Shape>(Box(name, ma, min, max));

  scene.addShape(name, box);
}

void Sdfloader::create_sphere(std::istringstream& iss)
{
  //sphere gets name, middle point vector and name of material
  std::string name, materialName;
  float x,y,z,r;

  iss >> name >> x >> y >> z;
  glm::vec3 mp(x,y,z);

  iss >> r;

  iss >> materialName;

  Material* ma = scene.getMaterial(materialName); //get the material and create object

  std::shared<Sphere> sphere = std::make_shared<Shape>(Sphere(name, ma, mp, r));

  scene.addShape(name, sphere);

  return ;
}

void Sdfloader::create_cam(std::istringstream& iss)
{
  //cam gets name, fov_x, vectors for direction and position
  std::string name;
  float fov_x,x,y,z;

  iss >> name >> fov_x >> x >> y >> z;

  glm::vec3 eye(x,y,z);

  iss >> x >> y >> z;

  glm::vec3 dir(x,y,z);

  iss >> x >> y >> z;

  glm::vec3 up(x,y,z);

  auto camera = std::make_shared<Camera>(name, fov_x, eye, dir, up);

  scene.addCam(camera);

  return ;
}