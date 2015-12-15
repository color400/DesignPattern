#ifndef __CDEFENSE_LIST_PATH_OBSERVER_HEADER__
#define __CDEFENSE_LIST_PATH_OBSERVER_HEADER__


#include <stdio.h>
#include <string>
#include <list>
#include <boost/thread/shared_mutex.hpp>

namespace color400{

class SubjectPath;

class Observer
{
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void Update( SubjectPath * pSubject ) = 0;
};


class ObserverPath : public Observer
{
public:
    void Update( SubjectPath * pSubject );
    std::wstring GetString() ;

private:
    std::wstring m_wstrPath;
};


class SubjectPath
{
public:
    void Attach(Observer * pObserver) ;
    void Detach(Observer * pObserver) ;
    void Notify() ;
    void SetPath(const std::wstring & wstrPath);
    std::wstring GetPath() ;

private:
    std::list<Observer*> m_Observers;
    boost::shared_mutex m_mutexContainer;
    boost::shared_mutex m_mutexPath;
    std::wstring m_wstrPath;
};

}; //namespace color400




#endif /* __CDEFENSE_LIST_PATH_OBSERVER_HEADER__ */
