#include <iostream>
#include "ClassA.h"
#include "World.h"

CClassA::CClassA(CWorld* world) : CBaseClass(world)
{
	name = "Class A";
	world->eventSignal.connect(boost::bind(&CClassA::WorldSignalHandler, this, boost::placeholders::_1, boost::placeholders::_2));
}

void CClassA::SendSignal()
{
	std::cout << "SendSignal(): A class" << std::endl;
	eventSignal(this, "Hello");
}

void CClassA::WorldSignalHandler(void* sender, std::string message)
{
	std::cout << name << " received a \"" << message << "\" message from World" << std::endl;
}
