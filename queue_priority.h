#ifndef QUEUE_PRIORITY_H
#define QUEUE_PRIORITY_H

#include "data_type.h"
#include <queue>
#include <algorithm>
#include <vector>

template <typename T>
class QueuePriority : public std::priority_queue<T, std::vector<T>>
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
        QueuePriority(unsigned int max_size) // do not go over UINT32_MAX
        {
            //init queue size value
            m_queue_max_size = max_size;
        }

        //======================================================================
        //  QueuePriority : insertData
        //
        ///  insert data in queue with order of priority and time insertion
        //
        /// @param[in] value
        ///      data to insert
        //======================================================================
        void insertData(T value)
        {
            value.m_insertTime = std::chrono::system_clock::now();

            if (static_cast<unsigned int>(this->size()) == m_queue_max_size) {
                eraseLast();
            }
            std::cout << "Insert" << value << std::endl;
            this->push(value);
        }

        //======================================================================
        //  QueuePriority : debugQueue
        //
        ///  debug the conatiner 
        //======================================================================
        void debugQueue()
        {
            for( auto debug : this->c)
            {
                std::cout << debug << std::endl;
            }
        }

    private:

        //======================================================================
        //  QueuePriority : eraseLast
        //
        ///  erase last queue value
        //======================================================================
        void eraseLast()
        {
            auto lastQueue = std::min_element(this->c.begin(),this->c.end());
            std::cout << "Erase" << *lastQueue << std::endl;
            this->c.erase(lastQueue);
        }

        unsigned int m_queue_max_size;
};

#endif // QUEUE_PRIORITY_H