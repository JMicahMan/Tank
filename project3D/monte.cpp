#include "monte.h"
#include "Gizmos.h"
#include "Input.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <cstdlib>
#include <ctime>

using glm::vec3;
using glm::vec4;
using glm::mat4;
using aie::Gizmos;

monte::monte()
{
}

monte::~monte()
{
}

bool monte::startup()
{
	setBackgroundColour(0.25f, 0.25f, 0.25f);


	Gizmos::create(10000, 10000, 10000, 10000);


	m_viewMatrix = glm::lookAt(vec3(10), vec3(0), vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f,
		getWindowWidth() / (float)getWindowHeight(),
		0.1f, 1000.f);

	return true;
}

void monte::shutdown()
{
	Gizmos::destroy();
}

void monte::update(float deltaTime)
{


	float time = getTime();

	//m_viewMatrix = glm::lookAt(vec3(glm::sin(time) * 10, 10, glm::cos(time) * 10),
	//vec3(0), vec3(0, 1, 0));

	Gizmos::clear();


	vec4 white(1);
	vec4 black(0, 0, 0, 1);
	for (int i = 0; i < 21; ++i) {
		Gizmos::addLine(vec3(-10 + i, 0, 10),
			vec3(-10 + i, 0, -10),
			i == 10 ? white : black);
		Gizmos::addLine(vec3(10, 0, -10 + i),
			vec3(-10, 0, -10 + i),
			i == 10 ? white : black);
	}

	Gizmos::addAABBFilled(vec3(0, 0, 0), vec3(1), vec4(0, 0.5f, 1, 0.25f));
	Gizmos::addAABBFilled(vec3(3, 0, 0), vec3(1), vec4(0, 0.5f, 1, 0.25f));
	Gizmos::addAABBFilled(vec3(6, 0, 0), vec3(1), vec4(0, 0.5f, 1, 0.25f));
	Gizmos::addAABBFilled(vec3(-3, 0, 0), vec3(1), vec4(0, 0.5f, 1, 0.25f));
	Gizmos::addAABBFilled(vec3(-6, 0, 0), vec3(1), vec4(0, 0.5f, 1, 0.25f));

	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_B))
	{
		std::srand;
		int proba = (rand() % 5);

		if (proba = 1)
		{
			Gizmos::addAABBFilled(vec3(0, 0, 0), vec3(1), vec4(0, 0.0f, 0, 0.0f));
		}

		if (proba = 2)
		{
			Gizmos::addAABBFilled(vec3(3, 0, 0), vec3(1), vec4(0, 0.0f, 0, 0.0f));
		}

		if (proba = 3)
		{
			Gizmos::addAABBFilled(vec3(6, 0, 0), vec3(1), vec4(0, 0.0f, 0, 0.0f));
		}

		if (proba = 4)
		{
			Gizmos::addAABBFilled(vec3(-3, 0, 0), vec3(1), vec4(0, 0.0f, 0, 0.0f));
		}

		if (proba = 5)
		{
			Gizmos::addAABBFilled(vec3(-6, 0, 0), vec3(1), vec4(0, 0.0f, 0, 0.0f));
		}
	}


	
	//Gizmos::addTransform(mat4(1));

	//Gizmos::addAABBFilled(vec3(0), vec3(1), vec4(0, 0.5f, 1, 0.25f));
	//Gizmos::addSphere(vec3(0, 2, 0), 1, 8, 8, vec4(1, 0, 0, 0.5f));
	//Gizmos::addDisk(vec3(0, 0, 0), 0.25, 1300, vec4(1, 1, 0, 1));

	//mat4 t = glm::rotate(mat4(1), time, glm::normalize(vec3(1, 1, 1)));
	//t[3] = vec4(-2, 0, 0, 1);
	//mat4 t = glm::rotate(mat4(1), 90.0f, glm::normalize(vec3(1, 1, 1)));
	//Gizmos::addCylinderFilled(vec3(0,2.5,1.5), 0.125f, 2, 1300, vec4(0, 1, 1, 1), &t);

	//Gizmos::add2DAABB(glm::vec2(getWindowWidth() / 2, 100),
	//glm::vec2(getWindowWidth() / 2 * (fmod(getTime(), 3.f) / 3), 20),
	//vec4(0, 1, 1, 1));

	

	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{

		Gizmos::addAABBFilled(vec3(0, 0, time), vec3(1), vec4(0, 0.5f, 1, 0.25f));
		Gizmos::addSphere(vec3(0, 2, time), 1, 8, 8, vec4(1, 0, 0, 0.5f));
		mat4 t = glm::rotate(mat4(1), 90.0f, glm::normalize(vec3(1, 1, 1)));
		Gizmos::addCylinderFilled(vec3(0, 2.5, time + 1.5f), 0.125f, 2, 1300, vec4(0, 1, 1, 1), &t);
	}

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		Gizmos::addAABBFilled(vec3(0, 0, -time), vec3(1), vec4(0, 0.5f, 1, 0.25f));
		Gizmos::addSphere(vec3(0, 2, -time), 1, 8, 8, vec4(1, 0, 0, 0.5f));
		mat4 t = glm::rotate(mat4(1), 90.0f, glm::normalize(vec3(1, 1, 1)));
		Gizmos::addCylinderFilled(vec3(0, 2.5, -time + 1.5f), 0.125f, 2, 1300, vec4(0, 1, 1, 1), &t);
	}

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		mat4 u = glm::rotate(mat4(1), time, glm::normalize(vec3(1, 1, 1)));
		Gizmos::addAABBFilled(vec3(0, 0, 0), vec3(1), vec4(0, 0.5f, 1, 0.25f), &u);
		mat4 m = glm::rotate(mat4(1), time, glm::normalize(vec3(1, 1, 1)));
		Gizmos::addSphere(vec3(0, 2, 0), 1, 8, 8, vec4(1, 0, 0, 0.5f), &m);
		mat4 t = glm::rotate(mat4(1), 90.f, glm::normalize(vec3(1, 1, 1)));
		Gizmos::addCylinderFilled(vec3(0, 2.5, 1.5f), 0.125f, 2, 1300, vec4(0, 1, 1, 1), &t);
	}

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void monte::draw()
{
	clearScreen();

	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f,
		getWindowWidth() / (float)getWindowHeight(),
		0.1f, 1000.f);

	Gizmos::draw(m_projectionMatrix * m_viewMatrix);

	Gizmos::draw2D((float)getWindowWidth(), (float)getWindowHeight());

}
