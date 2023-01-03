#include "queue_priority.h"
#include <unistd.h> 
#include <future>

int fillQueueFromThread(std::string threadName, QueuePriority *queue)
{
    queue->debugQueue();
    DataQueueType data1Thread("test1" + threadName, 10);
    DataQueueType data2Thread("test2" + threadName, 11);
    DataQueueType data3Thread("test3" + threadName, 12);
    DataQueueType data4Thread("test4" + threadName, 11);
    queue->insertData(data1Thread);
    usleep(random()% 1000+1);
    queue->insertData(data2Thread);
    queue->insertData(data3Thread);
    usleep(random()% 1000+1);
    queue->insertData(data4Thread);
    return 0;
}

int main()
{
    //test 1 Load queue
    std::cout << "TEST 1 : LOAD QUEUE" << std::endl;
    QueuePriority queueStr1(4);

    DataQueueType data1Str1("test1",10);
    DataQueueType data2Str1("test2",11);
    DataQueueType data3Str1("test3",12);
    DataQueueType data4Str1("test4",11);

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
    QueuePriority queueStr2(4);

    DataQueueType data1Str2("test1",10);
    DataQueueType data2Str2("test2",11);
    DataQueueType data3Str2("test3",12);
    DataQueueType data4Str2("test4",11);
    DataQueueType data5Str2("test5",13);

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
    QueuePriority queueStr3(10);

    DataQueueType data1Str3("test1",1);
    DataQueueType data2Str3("test2",50);
    DataQueueType data3Str3("test3",5);
    DataQueueType data4Str3("test4",10);
    DataQueueType data5Str3("test5",100);

    queueStr3.insertData(data1Str3);
    queueStr3.insertData(data2Str3);
    queueStr3.insertData(data3Str3);
    queueStr3.insertData(data4Str3);
    queueStr3.insertData(data5Str3);

    std::future<int> m_async1;
    m_async1 = std::async(std::launch::async,fillQueueFromThread,"thread1", &queueStr3);
    m_async1.wait();

    std::future<int> m_async2;
    m_async2 = std::async(std::launch::async,fillQueueFromThread,"thread2", &queueStr3);
    m_async2.wait();
    
    while (queueStr3.size() > 0)
    {
        std::cout << queueStr3.top().m_priority << " str : "<< queueStr3.top().m_data<< std::endl;
        queueStr3.pop();
    }

    return 0;
}