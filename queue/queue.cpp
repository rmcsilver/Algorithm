#include <iostream>

class Queue
{
private:
    int * DataList;
    int FrontIndex;
    int BackIndex;
    int Length;

public:
    Queue(int InLength = 0);
    ~Queue();
    bool IsEmpty();
    bool PushData(int InData);
    int PopData();
    int GetSize();
    void PrintData();
};

Queue::Queue(int InLength)
{
    DataList = new int[InLength];
    Length = InLength;
    FrontIndex = 0;
    BackIndex = 0;
}

Queue::~Queue()
{
    delete [] DataList;
    DataList = nullptr;
}

bool Queue::IsEmpty()
{
    return FrontIndex == BackIndex;
}

bool Queue::PushData(int InData)
{
    if(this->GetSize() >= Length)
    {
        std::cout << "큐가 가득찼습니다." << std::endl;
        return false;
    }

    DataList[BackIndex] = InData;
    BackIndex += 1;
    return true;
}

int Queue::PopData()
{
    if(this->GetSize() == 0)
    {
        std::cout << "큐에 데이터가 없습니다." << std::endl;
    }

    int OutData = DataList[FrontIndex];
    FrontIndex += 1;
    return OutData;
}

int Queue::GetSize()
{
    return BackIndex - FrontIndex;
}

void Queue::PrintData()
{
    for(int i=0; i< this->GetSize(); ++i)
    {
        std::cout << i << "번째 데이터 : " << DataList[i] << std::endl;
    }
}

int main(){
    
    Queue QueueList(10);

    std::cout << "큐의 현재 사이즈 :" << QueueList.GetSize() << std::endl; 

    for(int i=0; i<11; ++i)
    {
        QueueList.PushData(i);
    }

    QueueList.PrintData();
    std::cout << "큐의 현재 사이즈 :" << QueueList.GetSize() << std::endl; 

    for(int j=0; j<5; ++j)
    {
        QueueList.PopData();
    }

    QueueList.PrintData();
    std::cout << "큐의 현재 사이즈 :" << QueueList.GetSize() << std::endl; 
}
