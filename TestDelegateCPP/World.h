#include <string>
#include <boost/signals2.hpp>

class CWorld
{
public:
	CWorld();
	void SendSignal(std::string message);

	boost::signals2::signal<void(void* sender, std::string message)> eventSignal;
};
