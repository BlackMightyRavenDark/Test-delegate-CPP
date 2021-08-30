#include "BaseClass.h"

class CWorld;

class CClassB : public CBaseClass
{
public:
	CClassB(CWorld* world);
	void SendSignal() override;

private:
	void SignalHandler(void* sender, std::string message);

};
