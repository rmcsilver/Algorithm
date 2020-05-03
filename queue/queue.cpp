#include <iostream>

struct Node
{
    Node * PrevNode = nullptr;
    Node * NextNode = nullptr;
    int Data;
    Node(int InData = 0)
    {
        PrevNode = nullptr;
        NextNode = nullptr;
        Data = InData;
    }
};

void SafeDelete(Node * InNode)
{
    if(InNode)
    {
        delete InNode;
        InNode = nullptr;
    }
}

class Queue
{
private:
    Node * HeadNode;
    Node * TailNode;
    int ElementCount;

public:
    Queue();
    ~Queue();
    bool IsEmpty();
    bool PushData(int InData);
    int PopData();
    int GetSize();
    void PrintData();
};

Queue::Queue()
{
    HeadNode = nullptr;
    TailNode = nullptr;
    ElementCount = 0;
}

Queue::~Queue()
{
    if(TailNode)
    {
        Node * TempNode = TailNode->PrevNode;
        while(TempNode)
        {
            Node * DeleteNode = TempNode;
            TempNode = TempNode->PrevNode;
            SafeDelete(DeleteNode);
        }

        SafeDelete(TailNode);
    }

    SafeDelete(HeadNode);
}

bool Queue::IsEmpty()
{
    return ElementCount == 0;
}

bool Queue::PushData(int InData)
{
    if(ElementCount == 0)
    {
        HeadNode = new Node(InData);
        TailNode = HeadNode;
        
    }
    else
    {
        Node * NewNode = new Node(InData);
        this->TailNode->NextNode = NewNode;
        NewNode->PrevNode = this->TailNode;
        this->TailNode = NewNode;
    }

    ElementCount++;

    return true;
}

int Queue::PopData()
{
    if(ElementCount == 0)
    {
        std::cout << "큐에 데이터가 없습니다." << std::endl;
        return -1;
    }

    int Data = 0;
    Node * TempNode = HeadNode->NextNode;
    Data = HeadNode->Data;
    TempNode->PrevNode = nullptr;
    SafeDelete(HeadNode);
    HeadNode = TempNode;
    ElementCount--;

    return Data;
}

int Queue::GetSize()
{
    return ElementCount;
}

void Queue::PrintData()
{
    if(ElementCount == 0)
    {
        std::cout << "출력할 데이터가 없습니다." << std::endl;
    }

    int Count = 0;
    Node * TempNode = HeadNode;
    while(TempNode)
    {
        std::cout << Count + 1 << "번째 데이터 : " << TempNode->Data << std::endl; 
        TempNode = TempNode->NextNode;
        Count++;
    }
}

int main(){
    
    Queue QueueList;

    std::cout << "큐의 현재 사이즈 :" << QueueList.GetSize() << std::endl; 

    for(int i=0; i<11; ++i)
    {
        QueueList.PushData(i);
    }

    QueueList.PrintData();
    std::cout << "큐의 현재 사이즈 :" << QueueList.GetSize() << std::endl; 
    
    for(int j=0; j<5; ++j)
    {
        std::cout << "데이터 : " << QueueList.PopData() << " 팝업" << std::endl;
    }

    QueueList.PrintData();
    std::cout << "큐의 현재 사이즈 :" << QueueList.GetSize() << std::endl; 
}
