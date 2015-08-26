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
        
        if(sub == "sphere")
        {
          create_sphere(iss);
        }
        else if(sub == "box")
        {
          create_box(iss);
        }
        else if(sub == "composite")
        {

          issprint(iss);
          //create_composite(iss);

        }
      }
      else if(sub == "light")
      {
        iss >> sub;
        if(sub == "diffuse")
        {
          create_light(iss);
        }
        else if(sub == "ambient")
        {

        }
      }
      else if(sub == "camera")
      {
        create_cam(iss);
      }


    }
    else if(sub == "transform")
    {
      //create_transform(iss);
    }

  }
  

}

void Sdfloader::issprint(std::istringstream& iss)
{
  std::string name;
  iss >> name;
  
  std::shared_ptr<Composite> toAddCom = std::make_shared<Composite>(Composite(name));
  
  while(iss >> name)
  {
    std::shared_ptr<Shape> shape_ptr = scene_.getShape(name);
   // scene_.composites_->addShape(shape_ptr);
    toAddCom->addShape(shape_ptr);
  }

  if(scene_.getComposites() = nullptr)
  {
    scene_.addComposite(toAddCom);
  }
}

// void Sdfloader::create_composite(std::istringstream& iss)
// {
//   iss >> shape;


// }

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
  
  Material material = Material(name, ka, kd, ks, m);

  scene_.addMaterial(name, material);

    std::cout << name << " added" << std::endl;
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

  std::shared_ptr<Material> ma = scene_.getMaterial(materialName); //get the material and create object

  std::shared_ptr<Shape> box = std::make_shared<Box>(Box(name, ma, min, max));

  scene_.addShape(name, box);

  std::cout << name << " added" << std::endl;
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

  std::shared_ptr<Material> ma = scene_.getMaterial(materialName); //get the material and create object

  std::shared_ptr<Shape> sphere = std::make_shared<Sphere>(Sphere(name, ma, mp, r));

  scene_.addShape(name, sphere);

  std::cout << name << " added" << std::endl;
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

  //std::shared_ptr<Camera> camera = std::make_shared<Camera>(name, fov_x, eye, dir, up);

  Camera camera = Camera(name, fov_x, eye, dir, up);

  scene_.addCam(camera);

  std::cout << name << " added" << std::endl;
}

void Sdfloader::create_light(std::istringstream& iss)
{
  //creation of 
  std::string name;
  float x,y,z;
  
  iss >> name >> x >> y >> z;

  glm::vec3 location{x,y,z};

  iss >> x >> y >> z;

  Color color{x,y,z};

  std::shared_ptr<Light> light = std::make_shared<Light>(name, location, color);

  scene_.addLight(name, light);

  std::cout << name << " added" << std::endl;

}