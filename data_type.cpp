#include "data_type.h"

DataQueueType::DataQueueType(std::string data, unsigned int priority)
{
    m_data = data;
    m_priority = priority;
}

bool DataQueueType::operator<(DataQueueType p2) const
{

    return this->m_priority < p2.m_priority;
}