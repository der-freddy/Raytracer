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
      // else if(sub == "shape")
      // {
      //   iss >> sub
      //   if(sub == "Sphere")
      //   {
      //     create_sphere(iss);
      //   }
      //   else if(sub == "Box")
      //   {
      //     create_box(iss);
      //   }
      }
      // else if(sub == "light")
      // {
      //   create_light(iss);
      // }
      // else if(sub == "camera")
      // {
      //   create_camera(iss);
      // }


    }
    // else if(sub == "transform")
    // {
    //   create_transform(iss);
    // }

  }
  

}

void Sdfloader::create_material(std::istringstream& iss)
{
  std::string name;
  float r,g,b,m;
  iss >> name >> r >> g >> b;
  Color ka{r,g,b};

  iss >> r >> g >> b;
  Color kd{r,g,b};

  iss >> r >> g >> b;
  Color ks{r,g,b};

  iss >> m;
  
  scene_.materials[name] = Material(name,ka,kd,ks,m);

  return ;
}
