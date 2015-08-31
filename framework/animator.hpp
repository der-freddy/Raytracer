#ifndef BUW_ANIMATOR_HPP
#define BUW_ANIMATOR_HPP

#include <memory>
#include <string>
#include <vector>
#include <ostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <thread>
#include <vector>
#include <sdfloader.hpp>
#include "scene.hpp"
#include "renderer.hpp"

 class Animator
 {
 public:

 	Animator();
 	void generateFrames();

 private:
 	std::string outputPath_;
 	int frames_;
 };

 #endif