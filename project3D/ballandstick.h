#pragma once

#include <glm/fwd.hpp>
#include "Application.h"
#include <glm/mat4x4.hpp>

class ballandstick : public aie::Application
{
public:

	ballandstick();
	virtual ~ballandstick();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	glm::mat4	m_viewMatrix;
	glm::mat4	m_projectionMatrix;
};