#include <iostream>
#include <boost/signals2.hpp>

class CWorld
{
public:
	CWorld() {};

	void SendSignal(std::string message)
	{
		eventSignal(this, message);
	}

	boost::signals2::signal<void(void* sender, std::string message)> eventSignal;
};

class CBase
{
public:
	CBase(CWorld* world) 
	{
		this->world = world;
	};

	virtual void SendSignal() {}

	boost::signals2::signal<void(void* sender, std::string message)> eventSignal;

	std::string name;
	CWorld* world;
};

class A : public CBase
{
public:
	A(CWorld* world) : CBase(world)
	{
		name = "Class A";
		world->eventSignal.connect(boost::bind(&A::WorldSignalHandler, this, boost::placeholders::_1, boost::placeholders::_2));
	}

	void SendSignal() override
	{
		std::cout << "SendSignal(): A class" << std::endl;
		eventSignal(this, "Hello");
	}

private:
	void WorldSignalHandler(void* sender, std::string message)
	{
		std::cout << name << " received a \"" << message << "\" message from World" << std::endl;
	}
};

class B : public CBase
{
public:
	B(CWorld* world) : CBase(world)
	{
		name = "Class B";
		eventSignal.connect(boost::bind(&B::SignalHandler, this, boost::placeholders::_1, boost::placeholders::_2));
	}

	void SendSignal() override
	{
		std::cout << "SendSignal(): B class" << std::endl;
		eventSignal(this, "Bye");
	}

private:
	void SignalHandler(void* sender, std::string message)
	{
		CBase* obj = (CBase*)sender;
		std::cout << "Class B received a " << "\"" << message << "\" message from " << obj->name << std::endl;
	}
};

void SignalHandler(void* sender, std::string message)
{
	CBase* obj = (CBase*)sender;
	std::cout << "Received a \"" << message << "\" message from " << obj->name << std::endl;
}

int main()
{
	CWorld* world = new CWorld();

	A* a = new A(world);
	B* b = new B(world);

	a->eventSignal.connect(&SignalHandler);
	b->eventSignal.connect(&SignalHandler);

	a->SendSignal();
	b->SendSignal();

	world->SendSignal("Hi!");
	
	delete a;
	delete b;

	delete world;

	return 0;
}
