#include "BaseClass.h"
#include "World.h"

CBaseClass::CBaseClass(CWorld* world)
{
	this->world = world;
}

void CBaseClass::SendSignal() {};
