#include "BaseClass.h"

class CWorld;

class CClassA : public CBaseClass
{
public:
	CClassA(CWorld* world);
	void SendSignal() override;

private:
	void WorldSignalHandler(void* sender, std::string message);

};
