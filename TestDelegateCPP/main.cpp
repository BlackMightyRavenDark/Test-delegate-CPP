#include <iostream>
#include "ClassA.h"
#include "ClassB.h"
#include "World.h"

void SignalHandler(void* sender, std::string message)
{
	CBaseClass* obj = (CBaseClass*)sender;
	std::cout << "Received a \"" << message << "\" message from " << obj->name << std::endl;
}

int main()
{
	CWorld* world = new CWorld();

	CClassA* classA = new CClassA(world);
	CClassB* classB = new CClassB(world);

	classA->eventSignal.connect(&SignalHandler);
	classB->eventSignal.connect(&SignalHandler);

	classA->SendSignal();
	classB->SendSignal();

	world->SendSignal("Hi!");
	
	delete classA;
	delete classB;

	delete world;

	return 0;
}
