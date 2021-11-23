#ifndef MAIN_HPP
#define MAIN_HPP

#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#if defined(WIN32)
#define STBI_MSC_SECURE_CRT
#endif

#include <SingleFileHeaders/tiny_gltf.h>

tinygltf::Model model;
tinygltf::TinyGLTF loader;
std::string err;
std::string warn;

#endif
