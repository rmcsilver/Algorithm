#include <iostream>

struct Node
{
    Node * PrevNode;
    Node * NextNode;
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

class Stack
{
    private:
        Node * HeadNode;
        Node * TailNode;
        int ElementCount;

    public:
        Stack();
        ~Stack();
        bool IsEmpty();
        int GetSize();
        bool PushData(int InData);
        int PopData();
        void PrintData();
};

Stack::Stack()
{
    HeadNode = nullptr;
    TailNode = nullptr;
    ElementCount = 0;
}

Stack::~Stack()
{
    if(TailNode)
    {
        Node * TempNode = TailNode->PrevNode;
        while(TempNode)
        {
            Node * DeleteNode = TempNode;
            TempNode = TempNode->PrevNode;
            SafeDelete(DeleteNode);
            ElementCount--;
        }
       
        TailNode = nullptr;
    }

    HeadNode = nullptr;
}

bool Stack::IsEmpty()
{
    return ElementCount == 0;
}

int Stack::GetSize()
{
    return ElementCount;
}

bool Stack::PushData(int InData)
{
    if(HeadNode == nullptr)
    {
        Node * PushNode = new Node(InData);
        HeadNode = PushNode;
        TailNode = HeadNode;
    }
    else
    {
        Node * PushNode = new Node(InData);
        Node * TempNode = this->TailNode;
        TempNode->NextNode = PushNode;
        PushNode->PrevNode = TempNode;
        this->TailNode = PushNode;
    }

    ElementCount++;

    return true;
}

int Stack::PopData()
{
    if(ElementCount == 0)
    {
        std::cout << "스택에 데이터가 없습니다." << std::endl;
        return -1;
    }

    int Data = 0;
    Node * PopNode = this->TailNode;
    Data = PopNode->Data;
    PopNode->PrevNode->NextNode = nullptr;
    this->TailNode = PopNode->PrevNode;
    SafeDelete(PopNode); 
    ElementCount--;

    return Data;
}

void Stack::PrintData()
{
    int Count = 0;
    Node * TempNode = HeadNode;
    while(TempNode)
    {
        std::cout << Count + 1 << "번째 데이터 : " << TempNode->Data << std::endl;
        TempNode = TempNode->NextNode;
    }
}

int main()
{
    Stack StackList;

    std::cout << "스택 사이즈 : " << StackList.GetSize() << std::endl;
    for(int i=0; i<15; ++i)
    {
        StackList.PushData(i);
    }

    StackList.PrintData();
    std::cout << "스택 사이즈 : " << StackList.GetSize() << std::endl;
    
    
    for(int j=0; j<3; ++j)
    {
        std::cout << StackList.PopData() << " 데이터 팝업" << std::endl;
    }

    StackList.PrintData();
    std::cout << "스택 사이즈 : " << StackList.GetSize() << std::endl;
    
}
