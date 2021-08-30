#pragma once
#include <string>
#include <boost/signals2.hpp>

class CWorld;

class CBaseClass
{
public:
	CBaseClass(CWorld* world);
	virtual void SendSignal();

	boost::signals2::signal<void(void* sender, std::string message)> eventSignal;

	std::string name;
	CWorld* world;
};
