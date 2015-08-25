# CMake generated Testfile for 
# Source directory: /home/hans/Desktop/Raytracer
# Build directory: /home/hans/Desktop/Raytracer/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(tests "/home/hans/Desktop/Raytracer/build/build/Debug/tests")
SUBDIRS(external/glfw-3.0.3)
SUBDIRS(framework)
SUBDIRS(source)
SUBDIRS(tests)
