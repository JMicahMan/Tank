#include "Application3D.h"
#include "ballandstick.h"
#include "monte.h"

int main() {
	
	// allocation
	//auto app = new Application3D();
	//auto app = new monte();
	auto app = new ballandstick();


	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}