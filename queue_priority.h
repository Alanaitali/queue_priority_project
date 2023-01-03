#ifndef QUEUE_PRIORITY_H
#define QUEUE_PRIORITY_H

#include "data_type.h"
#include <queue>

class QueuePriority : public std::priority_queue<DataQueueType, std::vector<DataQueueType>>
{
    public:
        QueuePriority(unsigned int max_size);
        void insertData(DataQueueType value);
        void eraseLast();

    private:
        unsigned int m_queue_max_size;
};

#endif // QUEUE_PRIORITY_H