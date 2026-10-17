#pragma once
#include<list>

class IObserver{
    public:
        virtual void update() = 0;
};

class Subject{
    
    std::list<IObserver*> obsevers;
    public:
        void addObserver(IObserver* o){ obsevers.push_back(o); }
        void removeObserver(IObserver* o){ obsevers.remove(o); }
        void onNotify(){ for(IObserver* o : obsevers) o->update();};
};