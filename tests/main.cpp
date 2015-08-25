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

// TEST_CASE("Sphere","[Sphere]")
// {
// 	Sphere s1{};

// 	REQUIRE(s1.radius() == 0);
// 	REQUIRE(s1.mp().x == 0);
// 	REQUIRE(s1.mp().y == 0);
// 	REQUIRE(s1.mp().z == 0);

// 	double r = 3;
// 	glm::vec3 v{3};
// 	Sphere s2{v, r};

// 	REQUIRE(s2.radius() == 3);
// 	REQUIRE(s2.mp().x == 3);
// 	REQUIRE(s2.mp().y == 3);
// 	REQUIRE(s2.mp().z == 3);
// 	REQUIRE(Approx(s2.volume()) == 113.097);
// 	REQUIRE(Approx(s2.area()) == 113.097);


// 	Color red(255 , 0 , 0);
// 	Material m1("m1", red, red, red, 0);
// 	glm::vec3 position (0);
// 	Sphere s3{v, r, "s3", m1};

// 	REQUIRE(s3.name() == "s3");
// 	REQUIRE(s3.material().ka() == red);
// }

// TEST_CASE("Box","[Box]")
// {
// 	Box b1{};

// 	REQUIRE(b1.min().x == 0);
// 	REQUIRE(b1.min().y == 0);
// 	REQUIRE(b1.min().z == 0);

// 	REQUIRE(b1.max().x == 1.0f);
// 	REQUIRE(b1.max().y == 1.0f);
// 	REQUIRE(b1.max().z == 1.0f);

// 	glm::vec3 max{6};
// 	glm::vec3 min{3};
// 	Box b2{max, min};

// 	REQUIRE(b2.min().x == 3);
// 	REQUIRE(b2.min().y == 3);
// 	REQUIRE(b2.min().z == 3);

// 	REQUIRE(b2.max().x == 6);
// 	REQUIRE(b2.max().y == 6);
// 	REQUIRE(b2.max().z == 6);

// 	REQUIRE(b2.area() == 54);
// 	REQUIRE(b2.volume() == 27);

// 	Color green(0 , 255 , 0);
// 	Material m2("m2", green, green, green, 0);
// 	Box b3{max, min, "b3", m2};
	
// 	REQUIRE(b3.name() == "b3");
// 	REQUIRE(b3.material().kd() == green);

// }

// TEST_CASE("ostream","[ostream]")
// {

// 	std::cout << "===========================\n";
// 	std::cout << "======= Aufgabe 6.5 =======\n";
// 	std::cout << "===========================\n";

// 	Color black(0,0,0);
// 	Material m3("m3", black, black, black, 0);
// 	glm::vec3 max{6};
// 	glm::vec3 min{3};
// 	Box b1{max, min, "b", m3};

// 	double r = 3;
// 	glm::vec3 v{3};
// 	Sphere s1{v, r, "s", m3};

// 	std::cout << b1 << "\n";
// 	std::cout << s1 << "\n";

// }



// TEST_CASE("intersectRaySphere","[intersect]")
// {
// 	//Ray
// 	glm::vec3 ray_origin(0.0 ,0.0 ,0.0);
	
// 	glm::vec3 ray_direction(0.0 ,0.0 ,1.0);
// 	// Sphere
	
// 	glm::vec3 sphere_center(0.0 ,0.0 ,5.0);
	
// 	float sphere_radius(1.0);
	
// 	float distance(0.0);
	
// 	auto result = glm::intersectRaySphere(ray_origin ,ray_direction,sphere_center,sphere_radius*sphere_radius,distance);
	
// 	REQUIRE(distance == Approx(4.0f));
// }


// TEST_CASE("Aufgabe6_8", "[Aufgabe6_8]")
// {	
// 	std::cout << "===========================\n";
// 	std::cout << "======= Aufgabe 6.8 =======\n";
// 	std::cout << "===========================\n";
// 	Color blue(0 , 0 , 255);
// 	Material m4("m4", blue, blue, blue, 0);
// 	glm::vec3 position (0);

// 	Sphere* s1 = new Sphere(position,1.2,"sphere0",m4);
// 	Shape* s2 = new Sphere(position,1.2,"sphere1",m4);
// 	s1 -> print(std::cout);
// 	s2 -> print(std::cout);
// 	delete s1;
// 	delete s2;
// }

// TEST_CASE("intesect_box1", "[shouldntPass]")
// {
// 	Color blue(0 , 0 , 255);
// 	Material m4("m4", blue, blue, blue, 0);
// 	Box box = Box{{3.0,3.0,3.0}, {-1.0,2.0,1.0}, "Box" , m4};
// 	Ray ray = Ray{{0.0,4.0,2.0}, {0.218, -0.436, 0.873}};

// 	REQUIRE(!box.intersectBox(ray));

// }

// TEST_CASE("intesect_box2", "[shouldPass]")
// {
// 	Color blue(0 , 0 , 255);
// 	Material m4("m4", blue, blue, blue, 0);
// 	Box box = Box{{3.0,3.0,3.0}, {0.0,0.0,0.0}, "untitled box", m4};
// 	Ray ray = Ray{{0.0,0.0,0.0}, {1.0, 1.0, 1.0}};

//  REQUIRE(box.intersectBox(ray));
// }

// TEST_CASE("intesect_box3", "[shouldPass]")
// {
// 	Color blue(0 , 0 , 255);
// 	Material m4("m4", blue, blue, blue, 0);	
//  	Box box = Box{{9.0,9.0,9.0}, {5.0,5.0,5.0}, "untitled box", m4};
//  	Ray ray = Ray{{0.0,0.0,0.0}, {7.0, 7.0, 7.0}};

//  REQUIRE(box.intersectBox(ray));
// }
// 
TEST_CASE("sdfloader", "[checkload]")
{
	Sdfloader s{};

	std::string p = "../framework/input/sdf_test.txt";
	s.readSdf(p);

	REQUIRE(s.scene().material().size() == 1);

	REQUIRE(s.scene().shapes_.size() == 1);

	REQUIRE(s.scene().lights_.size() == 1);

	REQUIRE(s.scene().cam_.getName() == "eye");

	std::shared_ptr<Scene> scene = std::make_shared<Scene>(s.scene());

	Renderer renderer = Renderer{800, 600, "test.ppm", scene};
	renderer.render();
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
