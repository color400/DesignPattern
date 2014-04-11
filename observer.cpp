#include <iostream>

class Subject;
class Observer
{
public: 
    virtual void update(Subject *) = 0;

protected:
    Observer();

};

class ConObserver: public Observer
{
public:
    ConObserver();
    void update(Subject *sub)
    {
    };
};

class Subject
{
public:
    virutal ~Subject();
    virtual void attach(Observer* obs)
    {
        m_registeredSubjects.insert(obs);
    };
    
    virtual void detach(Observer* obs)
    {
        m_registeredSubjects.erase(obs);
    };
    
    virtual void notify()
    {
        for( auto iter : m_registeredSubjects )
            obs->update(this);
    };

protected:
    Subject();
private:
    std::unorder_set<Subject*> m_registeredSubjects;
};


class ConSubject: public Subject
{
public:
    ConSubject();
    
protected:
};




