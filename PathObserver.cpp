
void ObserverPath::Update( SubjectPath * pSubject )
{
    m_wstrPath = pSubject->GetPath();
};

std::wstring ObserverPath::GetString() 
{ 
    return m_wstrPath; 
};

void SubjectPath::Attach(Observer * pObserver) 
{ 
    boost::unique_lock<boost::shared_mutex> lock(m_mutexContainer);
    m_Observers.push_back(pObserver); 
}

void SubjectPath::Detach(Observer * pObserver)
{
    boost::unique_lock<boost::shared_mutex> lock(m_mutexContainer);
    m_Observers.remove(pObserver);
}


void SubjectPath::Notify() 
{ 
    boost::shared_lock<boost::shared_mutex> lock(m_mutexContainer);

    for(auto & iter: m_Observers)
    {
        iter->Update(this);
    }
}

void SubjectPath::SetPath(const std::wstring & wstrPath)
{
    boost::unique_lock<boost::shared_mutex> lock(m_mutexPath);
    m_wstrPath.assign(wstrPath);
}

std::wstring SubjectPath::GetPath() 
{
    boost::shared_lock<boost::shared_mutex> lock(m_mutexPath);
    std::wstring wstrPath(m_wstrPath);
    return wstrPath; 
}
