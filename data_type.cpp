#include "data_type.h"

DataQueueType::DataQueueType(std::string data, unsigned int priority)
{
    m_data = data;
    m_priority = priority;
}

bool DataQueueType::operator<(DataQueueType p2) const
{
    if(this->m_priority == p2.m_priority)
    {
        //std::cout<<"is equal"<<std::endl;
        if(std::chrono::duration_cast<std::chrono::microseconds>(this->m_insertTime - p2.m_insertTime).count() < 0) {
            return false;
        }
        else {
            return true;
        }
    }
    //std::cout<<"is dif"<<std::endl;
    return this->m_priority < p2.m_priority;
}

std::ostream& operator<<(std::ostream& os, const DataQueueType& dt)
{
    os << " data : " << dt.m_data << " priority : " << dt.m_priority;
    return os;
}
