#include "World.h"

CWorld::CWorld() {};

void CWorld::SendSignal(std::string message)
{
	eventSignal(this, message);
}
