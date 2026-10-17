#pragma once
#include <glm/glm.hpp>
#include <array>
#include <vector>
#include <string>
#include <vulkan/vulkan.h>
/*
struct Vertex{
    glm::vec3 position;
    glm::vec3 normal;
	glm::vec2 texcoord;
};

VkVertexInputBindingDescription getBindingDescription();
std::array<VkVertexInputAttributeDescription,3> getAttributeDescription();


class mesh{
    std::vector<Vertex> vertices;
    std::vector<uint16_t> indices;

    public:

    mesh();
    mesh(std::string path);
    void addVertex(Vertex vx);
    void addIndex(uint16_t index);
};
*/