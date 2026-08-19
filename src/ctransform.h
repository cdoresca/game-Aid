#pragma once
#include <glm/glm.hpp>

class CTransform {

    glm::vec3 m_position;
    glm::vec3 m_velocity;

    public:
        CTransform(); 
        CTransform(glm::vec3 position, glm::vec3 velocity);
        const glm::vec3& getPosition() const;
        const glm::vec3& getVelocity() const;
};
