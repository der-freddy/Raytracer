#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "sphere.hpp"
#include "box.hpp"
#include <iostream>
#include "sdfloader.hpp"
#include "renderer.hpp"
#include "animator.hpp"

TEST_CASE("sdfloader", "[checkload]")
{
	Sdfloader s{};

	std::string p = "../framework/input/sdf_test.txt";
	s.readSdf(p);

	std::shared_ptr<Scene> scene = std::make_shared<Scene>(s.scene());

	Renderer renderer = Renderer{400, 400, "test.ppm", scene};
	renderer.render();

	//for animator
	//Animator ani{};
	//ani.generateFrames();
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
