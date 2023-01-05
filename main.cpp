#include "queue_priority.h"
#include <unistd.h> 
#include <future>

int fillStrQueueFromThread(std::string threadName, QueuePriority<DataQueueType<std::string>>* queue)
{
    DataQueueType<std::string> data1Thread("test1" + threadName, 10);
    DataQueueType<std::string> data2Thread("test2" + threadName, 11);
    DataQueueType<std::string> data3Thread("test3" + threadName, 12);
    DataQueueType<std::string> data4Thread("test4" + threadName, 11);
    queue->insertData(data1Thread);
    queue->insertData(data2Thread);
    queue->insertData(data3Thread);
    queue->insertData(data4Thread);
    return 0;
}

int fillIntQueueFromThread(int intHeader, QueuePriority<DataQueueType<int>>* queue)
{
    DataQueueType<int> data1Thread(1 + intHeader, 10);
    DataQueueType<int> data2Thread(2 + intHeader, 11);
    DataQueueType<int> data3Thread(3 + intHeader, 12);
    DataQueueType<int> data4Thread(4 + intHeader, 11);
    queue->insertData(data1Thread);
    queue->insertData(data2Thread);
    queue->insertData(data3Thread);
    queue->insertData(data4Thread);
    return 0;
}

int main()
{
    //test 1 Load queue
    std::cout << "TEST 1 : LOAD QUEUE" << std::endl;
    QueuePriority<DataQueueType<std::string>> queueStr1(4);

    DataQueueType<std::string> data1Str1("test1",10);
    DataQueueType<std::string> data2Str1("test2",11);
    DataQueueType<std::string> data3Str1("test3",12);
    DataQueueType<std::string> data4Str1("test4",11);

    queueStr1.insertData(data1Str1);
    queueStr1.insertData(data2Str1);
    queueStr1.insertData(data3Str1);
    queueStr1.insertData(data4Str1);

    while (queueStr1.size() > 0)
    {
        std::cout << queueStr1.top().m_priority << " str : "<< queueStr1.top().m_data<< std::endl;
        queueStr1.pop();
    }

    //test 2 Load queue more than max queue size
    std::cout << "TEST 2 : LOAD QUEUE MORE THAN MAX QUEUE SIZE" << std::endl;
    QueuePriority<DataQueueType<std::string>> queueStr2(4);

    DataQueueType<std::string> data1Str2("test1",10);
    DataQueueType<std::string> data2Str2("test2",11);
    DataQueueType<std::string> data3Str2("test3",12);
    DataQueueType<std::string> data4Str2("test4",11);
    DataQueueType<std::string> data5Str2("test5",13);

    queueStr2.insertData(data1Str2);
    queueStr2.insertData(data2Str2);
    queueStr2.insertData(data3Str2);
    queueStr2.insertData(data4Str2);
    queueStr2.insertData(data5Str2);

    while (queueStr2.size() > 0)
    {
        std::cout << queueStr2.top().m_priority << " str : "<< queueStr2.top().m_data<< std::endl;
        queueStr2.pop();
    }

    //test 3 insert from thread pop in main
    std::cout << "TEST 3 : INSERT FROM THREAD POP IN MAIN" << std::endl;
    QueuePriority<DataQueueType<std::string>> queueStr3(10);

    DataQueueType<std::string> data1Str3("test1",1);
    DataQueueType<std::string> data2Str3("test2",50);
    DataQueueType<std::string> data3Str3("test3",5);
    DataQueueType<std::string> data4Str3("test4",10);
    DataQueueType<std::string> data5Str3("test5",100);

    queueStr3.insertData(data1Str3);
    queueStr3.insertData(data2Str3);
    queueStr3.insertData(data3Str3);
    queueStr3.insertData(data4Str3);
    queueStr3.insertData(data5Str3);

    std::future<int> m_async1;
    m_async1 = std::async(std::launch::async,fillStrQueueFromThread,"thread1", &queueStr3);
    m_async1.wait();

    std::future<int> m_async2;
    m_async2 = std::async(std::launch::async,fillStrQueueFromThread,"thread2", &queueStr3);
    m_async2.wait();
    
    while (queueStr3.size() > 0)
    {
        std::cout << queueStr3.top().m_priority << " str : "<< queueStr3.top().m_data<< std::endl;
        queueStr3.pop();
    }

    //test 4 insert from thread pop in main int value
    std::cout << "TEST 4 : INSERT FROM THREAD POP IN MAIN INT value" << std::endl;
    QueuePriority<DataQueueType<int>> queueStr4(10);

    DataQueueType<int> data1Str4(555,1);
    DataQueueType<int> data2Str4(666,50);
    DataQueueType<int> data3Str4(326,5);
    DataQueueType<int> data4Str4(222,10);
    DataQueueType<int> data5Str4(2566,100);

    queueStr4.insertData(data1Str4);
    queueStr4.insertData(data2Str4);
    queueStr4.insertData(data3Str4);
    queueStr4.insertData(data4Str4);
    queueStr4.insertData(data5Str4);

    std::future<int> m_async3;
    m_async3 = std::async(std::launch::async, fillIntQueueFromThread, 10, &queueStr4);
    m_async3.wait();

    std::future<int> m_async4;
    m_async4 = std::async(std::launch::async, fillIntQueueFromThread, 20, &queueStr4);
    m_async4.wait();
    
    while (queueStr4.size() > 0)
    {
        std::cout << queueStr4.top().m_priority << " str : "<< queueStr4.top().m_data<< std::endl;
        queueStr4.pop();
    }

    return 0;
}