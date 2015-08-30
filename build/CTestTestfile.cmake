# CMake generated Testfile for 
# Source directory: /home/hans/Desktop/Raytracer
# Build directory: /home/hans/Desktop/Raytracer/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(tests "/home/hans/Desktop/Raytracer/build/build/Release/tests")
subdirs(external/glfw-3.0.3)
subdirs(framework)
subdirs(source)
subdirs(tests)
