#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include"box.hpp"
#include"sphere.hpp"

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






























int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
