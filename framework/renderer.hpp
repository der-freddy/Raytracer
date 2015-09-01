#ifndef BUW_RENDERER_HPP
#define BUW_RENDERER_HPP

#include "color.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
#include <string>
#include <cmath>
#include <glm/glm.hpp>
#include "ray.hpp"
#include "scene.hpp"
#include "hit.hpp"

class Renderer
{
public:
  Renderer(unsigned w, unsigned h, std::string const& file, std::shared_ptr<Scene> const& scene);

  void render();
  void write(Pixel const& p);

  inline std::vector<Color> const& colorbuffer() const
  {
    return colorbuffer_;
  }

  Color raytrace(Ray const& ray, Color const& color, int depth) const;

//  bool closestIntersection(Hit const&, std::shared_ptr<Light> const&) const; 
  Color ka(std::shared_ptr<Shape> const& shape) const;
  Color kd(std::shared_ptr<Shape> const& shape) const;
  Color ks(std::shared_ptr<Shape> const& shape) const;
  float shade(Hit const& hit) const;
  Color getDiffuse(Hit const&) const;
  Color getSpecular(Hit const& hit) const;
  Color getRefl(Hit const& hit, int depth, Ray const&) const;
  Color getRefr(Hit const& hit, Ray const& ray, int depth) const;

private:
  unsigned width_;
  unsigned height_;
  std::vector<Color> colorbuffer_;
  std::string filename_;
  PpmWriter ppm_;
  std::shared_ptr<Scene> scene_;
  float fovDistance_;

};

#endif // #ifndef BUW_RENDERER_HPP
