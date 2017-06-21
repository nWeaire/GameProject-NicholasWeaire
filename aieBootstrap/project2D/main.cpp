#include "Application2D.h"
int main() 
{


	Application2D* app = new Application2D(); // Creates application 2D
	_ASSERT(app);
	app->run("AIE", 1280, 720, false); // Runs application 2D
	delete app; // Deletes Application 2D

	return 0;
}