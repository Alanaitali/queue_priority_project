#include "queue_priority.h"
#include <algorithm>
#include <vector>

QueuePriority::QueuePriority(unsigned int max_size) // do not go over UINT32_MAX
{
    //init queue size value
    m_queue_max_size = max_size;
}

void QueuePriority::insertData(DataQueueType value)
{ 
    value.m_insertTime = std::chrono::system_clock::now();

    if (static_cast<unsigned int>(this->size()) == m_queue_max_size) {
        eraseLast();
    }
    std::cout << "Insert" << value << std::endl;
    this->push(value);
}

void QueuePriority::eraseLast()
{
    auto lastQueue = std::min_element(this->c.begin(),this->c.end());
    std::cout << "Erase" << *lastQueue << std::endl;
    this->c.erase(lastQueue);
}

void QueuePriority::debugQueue()
{
    for( auto debug : this->c)
    {
        std::cout << debug << std::endl;
    }
}