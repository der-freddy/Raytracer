#include "hit.hpp"

Hit::Hit():
hit_{false}, distance_{INFINITY}, intersect_{glm::vec3{INFINITY, INFINITY, INFINITY}}, normal_{glm::vec3{INFINITY, INFINITY, INFINITY}}, shape_{nullptr}
{}

Hit::Hit(bool hit, double distance, glm::vec3 const& intersect, glm::vec3 normal, 
		std::shared_ptr<Shape> shape):
hit_{hit}, distance_{distance}, intersect_{intersect}, shape_{shape}
{}