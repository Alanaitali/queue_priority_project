#include "queue_priority.h"

QueuePriority::QueuePriority(unsigned int max_size) // do not go over UINT32_MAX
{
    //init queue size value
    m_queue_max_size = max_size;
}

void QueuePriority::insertData(DataQueueType value)
{
    //overload << operator
    //std::cout<<value<<std::endl;
    if (static_cast<unsigned int>(this->size()) == m_queue_max_size) {
        eraseLast();
    }
    this->push(value);
}

void QueuePriority::eraseLast()
{
    this->c.erase(this->c.end()-1);
}