#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include <iostream>
#include <ctime>
#include <chrono>

//======================================================================
//  DataQueueType class
//
/// element to add in priority queue
//======================================================================
template<typename T>
class DataQueueType
{
    public:

        //======================================================================
        //  DataQueueType : DataQueueType
        //
        ///  constructor, store data and priority in private member var
        //
        /// @param[in] data
        ///      symbolise data in queue
        //
        /// @param[in] priority
        ///     priority number in queue
        //======================================================================
        DataQueueType(const T& data, unsigned int priority)
        {
            m_data = data;
            m_priority = priority;
        }
        
        //======================================================================
        //  DataQueueType : operator<
        //
        ///  overload, less operator to be able to use DataQueueType
        /// in std::priority_queue
        //
        /// @param[in] p2
        ///     DataQueueType datato compare
        //======================================================================
        bool operator<(DataQueueType p2) const
        {
            if(this->m_priority == p2.m_priority)
            {
                if(std::chrono::duration_cast<std::chrono::microseconds>(this->m_insertTime - p2.m_insertTime).count() < 0) {
                    return false;
                }
                else {
                    return true;
                }
            }
            return this->m_priority < p2.m_priority;
        }

        //======================================================================
        //  DataQueueType : operator<<
        //
        ///  overload, << operator to be able to cout data and priority
        //
        /// @param[in] p2
        ///     DataQueueType datato compare
        //======================================================================
        friend std::ostream& operator<<(std::ostream& os, const DataQueueType& dt)
        {
            os << " data : " << dt.m_data << " priority : " << dt.m_priority;
            return os;
        }

        unsigned int m_priority;
        T m_data;
        std::chrono::_V2::system_clock::time_point m_insertTime;
};
#endif // DATA_TYPE_H
