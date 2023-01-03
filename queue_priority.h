#ifndef QUEUE_PRIORITY_H
#define QUEUE_PRIORITY_H

#include "data_type.h"
#include <queue>

//======================================================================
//  QueuePriority class
//
/// inherit from priority_queue to insert DataQueueType element
//======================================================================

class QueuePriority : public std::priority_queue<DataQueueType, std::vector<DataQueueType>>
{
    public:

        //======================================================================
        //  QueuePriority : QueuePriority
        //
        ///  constructor, store data and priority in private member var
        //
        /// @param[in] max_size
        ///      max data queue 
        //======================================================================
        QueuePriority(unsigned int max_size);

        //======================================================================
        //  QueuePriority : insertData
        //
        ///  insert data in queue with order of priority and time insertion
        //
        /// @param[in] value
        ///      data to insert
        //======================================================================
        void insertData(DataQueueType value);

        void debugQueue();

    private:
        
        //======================================================================
        //  QueuePriority : eraseLast
        //
        ///  erase last queue value
        //======================================================================
        void eraseLast();

        unsigned int m_queue_max_size;
};

#endif // QUEUE_PRIORITY_H