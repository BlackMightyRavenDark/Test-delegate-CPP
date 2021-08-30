#include <iostream>
#include "ClassB.h"
#include "World.h"

CClassB::CClassB(CWorld* world) : CBaseClass(world)
{
	name = "Class B";
	eventSignal.connect(boost::bind(&CClassB::SignalHandler, this, boost::placeholders::_1, boost::placeholders::_2));
}

void CClassB::SendSignal()
{
	std::cout << "SendSignal(): B class" << std::endl;
	eventSignal(this, "Bye");
}

void CClassB::SignalHandler(void* sender, std::string message)
{
	CBaseClass* obj = (CBaseClass*)sender;
	std::cout << "Class B received a " << "\"" << message << "\" message from " << obj->name << std::endl;
}
