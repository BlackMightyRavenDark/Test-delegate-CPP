#include <iostream>
#include <boost/signals2.hpp>

class CBase
{
public:
	CBase() {};

	virtual void SendSignal() {}

	boost::signals2::signal<void(void*)> eventSignal;

	std::string name;
};

class A : public CBase
{
public:
	A() : CBase()
	{
		name = "Class A";
	}

	void SendSignal() override
	{
		std::cout << "SendSignal(): A class" << std::endl;
		eventSignal(this);
	}
};

class B : public CBase
{
public:
	B() : CBase()
	{
		name = "Class B";
	}

	void SendSignal() override
	{
		std::cout << "SendSignal(): B class" << std::endl;
		eventSignal(this);
	}
};

void SignalHandler(void* sender)
{
	CBase* obj = (CBase*)sender;
	std::cout << "Received a signal from " << obj->name << std::endl;
}

int main()
{
	A* a = new A();
	a->eventSignal.connect(&SignalHandler);
	a->SendSignal();
	delete a;

	B* b = new B();
	b->eventSignal.connect(&SignalHandler);
	b->SendSignal();
	delete b;

	return 0;
}
