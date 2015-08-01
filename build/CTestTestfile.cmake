# CMake generated Testfile for 
# Source directory: /home/freddy/Dokumente/Studium/Prog/Aufgabenblatt7/programmiersprachen-raytracer
# Build directory: /home/freddy/Dokumente/Studium/Prog/Aufgabenblatt7/programmiersprachen-raytracer/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(tests "/home/freddy/Dokumente/Studium/Prog/Aufgabenblatt7/programmiersprachen-raytracer/build/build/Release/tests")
subdirs(external/glfw-3.0.3)
subdirs(framework)
subdirs(source)
subdirs(tests)
