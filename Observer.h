#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Observer
{
public:
	virtual void update() = 0;
	~Observer();
};
class Observable
{
private:
	vector<Observer*> observers;
public:
	Observable() {}
	~Observable(){}
	virtual void update() {}
	void addObserver(Observer* obs)
	{
		this->observers.push_back(obs);
	}
	void removeObserver(Observer* obs)
	{
		this->observers.erase(remove(observers.begin(), observers.end(), obs));
	}
	void notify()
	{
		this->update();
		for (auto o : this->observers)
			o->update();
	}
};

