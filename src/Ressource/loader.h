#pragma once
#include "mesh.h"
#include "material.h"

void objLoader(std::string path, std::vector<mesh>& meshes,std::vector<material>& materials);

void gltfLoader(std::string path, std::vector<mesh>& meshes,std::vector<material>& materials);

void glbLoader(std::string path, std::vector<mesh>& meshes,std::vector<material>& materials);
