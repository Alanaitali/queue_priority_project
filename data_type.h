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

class DataQueueType
{
    public:

        //======================================================================
        //  DataQueueType : DataQueueType
        //
        ///  constructor, store data and priority in private member var
        //
        /// @param[in] data
        ///      string for symbolise data in queue
        //
        /// @param[in] priority
        ///     priority number in queue
        //======================================================================
        DataQueueType(std::string data, unsigned int priority);
        
        //======================================================================
        //  DataQueueType : operator<
        //
        ///  overload, less operator to be able to use DataQueueType
        /// in std::priority_queue
        //
        /// @param[in] p2
        ///     DataQueueType datato compare
        //======================================================================
        bool operator<(DataQueueType p2) const;

        //======================================================================
        //  DataQueueType : operator<<
        //
        ///  overload, << operator to be able to cout data and priority
        //
        /// @param[in] p2
        ///     DataQueueType datato compare
        //======================================================================
        friend std::ostream& operator<<(std::ostream& os, const DataQueueType& dt);

        //to use in private in futur
        unsigned int m_priority;
        std::string m_data;
        std::chrono::_V2::system_clock::time_point m_insertTime;
};
#endif // DATA_TYPE_H
