#ifndef GLTFLOADER_HPP
#define GLTFLOADER_HPP

#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#if defined(WIN32)
#define STBI_MSC_SECURE_CRT
#endif

#include <SingleFileHeaders/tiny_gltf.h>

static tinygltf::TinyGLTF GLTFLoader;

#endif
