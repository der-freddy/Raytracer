#ifndef BUW_ANIMATOR_HPP
#define BUW_ANIMATOR_HPP

#include <memory>
#include <string>
#include <vector>

#include "scene.hpp"
#include "renderer.hpp"

 class Animator
 {
 public:

 	Animator(std::string path, int frames);
 	void createFrames() const;

 private:
 	std::string outputPath_;
 	int frames_;
 };

 #endif