#pragma once

#include <glm/fwd.hpp>
#include "Application.h"
#include <glm/mat4x4.hpp>

class monte : public aie::Application
{
public:

	monte();
	virtual ~monte();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	glm::mat4	m_viewMatrix;
	glm::mat4	m_projectionMatrix;
};
