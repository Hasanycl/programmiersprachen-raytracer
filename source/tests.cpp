#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include"box.hpp"
#include"sphere.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include"ray.hpp"
#include"hitpoint.hpp"

/*
TEST_CASE("Box volume and area" , "[area and volume]"){

    Box b{ {3.0f, 4.0f, 3.0f},{4.0f, 6.0f, 5.0f},"Box",{0.1f,0.2f,0.4f} };
    REQUIRE(b.area() == Approx(16.0f));
    REQUIRE(b.volume() == Approx(4.0f));

    Box b1{ {4.0f , 2.0f ,2.0f},{7.0f, 8.0f , 9.0f},"whats in the Box",{0.4f,0.5f,0.8f} };
    REQUIRE(b1.area() == Approx(162.0f));
    REQUIRE(b1.volume() == Approx(126.0f));
}

TEST_CASE("Sphere volume and area", "[area and volume]") {

    Sphere s{ {3.0f, 2.0f , 4.0f}, 5.0f,"Sphere",{0.4f,0.5f,0.8f} };
    REQUIRE(s.area() == Approx(314.15927f));
    REQUIRE(s.volume() == Approx(523.59882f));

    Sphere s1{ {5.0f , 3.0f ,2.0f} , 3.8f , "Sphere1", { 0.4f,0.5f,0.8f } };
    REQUIRE(s1.area() == Approx(181.45839f));
    REQUIRE(s1.volume() == Approx(229.84729f));

}
*/

TEST_CASE(" intersect_ray_sphere ", "[intersect]"){
    // Ray
    glm::vec3 ray_origin{ 0.0f, 0.0f, 0.0f };
        // ray direction has to be normalized !
        // you can use :
        // v = glm :: normalize ( some_vector )
        glm::vec3 ray_direction{ 0.0f, 0.0f, 1.0f };
    // Sphere
    glm::vec3 sphere_center{ 0.0f ,0.0f, 5.0f };
    float sphere_radius{ 1.0f };
    float distance = 0.0f;
    auto result = glm::intersectRaySphere(
        ray_origin, ray_direction,
        sphere_center,
        sphere_radius * sphere_radius, // squared radius !!!
        distance);
    REQUIRE(distance == Approx(4.0f));
}

TEST_CASE(" intersect_ray_sphere2 ", "[intersect]") {

    Sphere s{ {0.0f, 6.0f , 0.0f}, 1.0f, "Sphere" ,{0.1f,0.1f,0.2f} };
    Ray ray{ {0.0f, 0.0f, 0.0f},{0.0f, 2.0f, 0.0f} };
    HitPoint hit = s.intersect(ray);
    REQUIRE(hit.intersected == true);
    REQUIRE(hit.t == Approx(5.0f));
    REQUIRE(hit.name == "Sphere");
    REQUIRE(hit.color.r == 0.1f);
    REQUIRE(hit.color.g == 0.1f);
    REQUIRE(hit.color.b == 0.2f);




    Sphere s1{ {5.0f, 1.0f , 0.0f}, 1.0f, "Sphere" ,{0.1f,0.1f,0.2f} };
    Ray ray1{ {0.0f, 0.0f, 0.0f},{0.0f, 0.0f, 4.0f} };
    HitPoint hit1 = s1.intersect(ray1);
    REQUIRE(hit1.intersected == false);
    REQUIRE(hit1.t == Approx(0.0f));


}





/*
TEST_CASE() {
    std::cout << "Task 5.8 ----------- - - - - - - - - - - - - - - - - - - - -" << "\n";
    Color red{ 255 , 0 , 0 };
    glm::vec3 position{ 0.0f, 0.0f, 0.0f };
    Sphere* s1 = new Sphere{ position , 1.2f,  "sphere0", red };
    Shape* s2 = new Sphere{ position , 1.2f, "sphere1" , red  };
    s1 -> print(std::cout) << "\n";
    s2 -> print(std::cout) << "\n";
    delete s1;
    delete s2;
    std::cout << "Task 5.8 done ---------- - - - - - - - - - - - - - - - - - - -" << "\n";
}


*/















int main(int argc, char *argv[])
{
    /*
    //idk if i should write these in a test case
    Sphere s{ {3.0f, 2.0f , 4.0f}, 5.0f,"Sphere",{0.4f,0.5f,0.8f} };
    Sphere s1{ {3.0f, 9.0f , 3.0f}, 6.4f,"Bored",{0.2f,0.2f,0.1f} };
    Box b{ {4.0f , 2.0f ,2.0f},{7.0f, 8.0f , 9.0f},"whats in the Box",{0.4f,0.5f,0.8f} };
    Box b1{ {3.0f , 2.0f ,1.0f},{7.0f, 8.0f , 9.0f},"Don Corleone",{0.2f,0.1f,0.8f } };
    std::cout << s << "\n";
    std::cout << s1 << "\n";
    std::cout << b << "\n";
    std::cout << b1 << "\n";
    */

  return Catch::Session().run(argc, argv);
}
