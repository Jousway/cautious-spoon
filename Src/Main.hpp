#ifndef MAIN_HPP
#define MAIN_HPP

#include <GLFW/glfw3.h>

#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS

#include <SingleFileHeaders/tiny_gltf.h>

#include "Quad.hpp"

tinygltf::Model model;
tinygltf::TinyGLTF loader;
std::string err;
std::string warn;

#endif
