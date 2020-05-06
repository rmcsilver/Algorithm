/*
 *  Program : LinkedList
 *  File : linkedlist.cpp
 *  Description : Double Linked List based C++ 
 *  Author : silver
 *  Notes : 
 *  Revisions : 2020/05/06 Create
 */

#include <iostream>

struct Node
{
public:
    int Data;
    Node * PrevNode;
    Node * NextNode;
    Node(int InData=0)
    {
        Data = InData;
        PrevNode = nullptr;
        NextNode = nullptr;
    }
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    int Size();
    bool IsEmpty();
    void Display();
    
    bool PushBack(Node * InElement);
    bool PushFront(Node * InElement);
    
    bool PopBack();
    bool PopFront();

    bool Remove(int InValue);
    bool Erase(int InPosition);
    bool Erase(int InBeginPosition, int InEndPosition);

private:
    Node * HeadNode;
    Node * TailNode;
    int ElementCount;
};

void SafeDelete(Node * InNode)
{
    if(InNode)
    {
        delete InNode;
        InNode = nullptr;
    }
}

void SafeDelete(LinkedList * InList)
{
    if(InList)
    {
        delete InList;
        InList = nullptr;
    }
}

LinkedList::LinkedList()
{
    HeadNode = nullptr;
    TailNode = nullptr;
    ElementCount = 0;
}

LinkedList::~LinkedList()
{
    if(!IsEmpty())
    {
        Node * CurrentNode = HeadNode;
        while(CurrentNode)
        {
            Node * DeleteNode = CurrentNode;
            CurrentNode = CurrentNode->NextNode;
            SafeDelete(DeleteNode);
        }
    }

    SafeDelete(HeadNode);
    SafeDelete(TailNode);
}

int LinkedList::Size()
{
    return ElementCount;
}

bool LinkedList::IsEmpty()
{ 
    return (HeadNode == nullptr || ElementCount == 0);
}   

void LinkedList::Display()
{
    if(IsEmpty())
    {
        std::cout << "출력할 데이터가 없습니다." << std::endl;
        return;
    }

    std::cout << "[Head]->";
    Node * CurrentNode = HeadNode;
    while(CurrentNode)
    {
        std::cout << "[" << CurrentNode->Data << "]->";
        CurrentNode = CurrentNode->NextNode;
    }
    std::cout << "[Tail]" << std::endl;
    std::cout << "현재 리스트의 사이즈는 " << Size() << " 입니다.\n" << std::endl;
}
    
bool LinkedList::PushBack(Node * InElement)
{
    if(InElement == nullptr)
    {
        std::cout << "Push실패. 입력값이 null 입니다." << std::endl;
        return false;
    }

    if(IsEmpty())
    {
        HeadNode = InElement;
        TailNode = HeadNode;
    }   
    else
    {
        Node * CurrentNode = TailNode;
        CurrentNode->NextNode = InElement;
        InElement->PrevNode = CurrentNode;
        TailNode = InElement;
    }

    ElementCount++;

    return true;
}

bool LinkedList::PushFront(Node * InElement)
{
    if(InElement == nullptr)
    {
        std::cout << "Push 실패. 입력값이 null 입니다." << std::endl;
        return false;
    }

    if(IsEmpty())
    {
        HeadNode = InElement;
        TailNode = HeadNode;
    }   
    else
    {
        Node * CurrentNode = HeadNode;
        CurrentNode->PrevNode = InElement;
        InElement->NextNode = CurrentNode;
        HeadNode = InElement;
    }

    ElementCount++;

    return true;
}   

bool LinkedList::PopBack()
{
    if(IsEmpty())
    {
        std::cout << "데이터가 없습니다." << std::endl;
        return false;
    }

    Node * PopNode = TailNode;
    TailNode = PopNode->PrevNode;
    PopNode->PrevNode->NextNode = nullptr;
    SafeDelete(PopNode);

    ElementCount--;
    return true;
}

bool LinkedList::PopFront()
{
    if(IsEmpty())
    {
        std::cout << "데이터가 없습니다." << std::endl;
        return false;
    }

    Node * PopNode = HeadNode;
    HeadNode = PopNode->NextNode;
    HeadNode->PrevNode = nullptr;
    SafeDelete(PopNode);

    ElementCount--;
    return false;
}

bool LinkedList::Remove(int InValue)
{
    if(IsEmpty())
    {
        std::cout << "삭제할 데이터가 없습니다." << std::endl;
        return false;
    }
    
    Node * CurrentNode = HeadNode;
    while(CurrentNode)
    {
        if(CurrentNode->Data == InValue)
        {
            if(HeadNode == TailNode)
            {
                HeadNode = nullptr;
                TailNode = nullptr;
                SafeDelete(CurrentNode);
                ElementCount--;
                return true;
            }
 
            if(CurrentNode == TailNode)
            { 
                TailNode = CurrentNode->PrevNode;
                TailNode->NextNode = nullptr;
                SafeDelete(CurrentNode);
                ElementCount--;
                return true;
            }

            if(CurrentNode == HeadNode)
            {
                HeadNode = CurrentNode->NextNode;
                HeadNode->PrevNode = nullptr;
                SafeDelete(CurrentNode);
                CurrentNode = HeadNode;
                ElementCount--;
            }
            else
            {
                CurrentNode->PrevNode->NextNode = CurrentNode->NextNode;
                CurrentNode->NextNode->PrevNode = CurrentNode->PrevNode;
                Node * TempNode = CurrentNode->NextNode;
                SafeDelete(CurrentNode);
                ElementCount--;
                CurrentNode = TempNode;
            }
        }
        else
        {
            CurrentNode = CurrentNode->NextNode;
        }
    }

    return false;
}

bool LinkedList::Erase(int InPosition)
{
    if(IsEmpty())
    {
        std::cout << "삭제할 데이터가 없습니다." << std::endl;
        return false;
    }

    if(InPosition > Size())
    {
        std::cout << "입력값 만큼의 데이터가 없습니다. 현재 리스트 사이즈 : " << Size() << std::endl;
        return false;
    }

    int Position = 0;
    Node * CurrentNode = HeadNode;
    while(CurrentNode)
    {
        Position++;
        if(Position == InPosition)
        {
            if(HeadNode == TailNode)
            {
                HeadNode = nullptr;
                TailNode = nullptr;
            }
            else if(CurrentNode == TailNode)
            {
                TailNode = CurrentNode->PrevNode;
                TailNode->NextNode = nullptr;
            }
            else
            {
                if(CurrentNode == HeadNode)
                {
                    HeadNode = CurrentNode->NextNode;
                    HeadNode->PrevNode = nullptr;
                }
                else
                {
                    CurrentNode->PrevNode->NextNode = CurrentNode->NextNode;
                    CurrentNode->NextNode->PrevNode = CurrentNode->PrevNode;
                }
            }

            SafeDelete(CurrentNode);
            ElementCount--;
            return true;
        }

        CurrentNode = CurrentNode->NextNode;
    }

    return false;
}

bool LinkedList::Erase(int InBeginPosition, int InEndPosition)
{
    return false;
}


int main()
{
    LinkedList * list = new LinkedList();

    Node * PushNode = nullptr;

    PushNode = new Node(100);
    list->PushBack(PushNode);
    list->Display();

    for(int i=0; i<10; ++i)
    {
        PushNode = new Node(i);
        list->PushBack(PushNode);
    }
    list->Display();

    PushNode = new Node(100);
    list->PushBack(PushNode);
    PushNode = new Node(100);
    list->PushBack(PushNode);
    PushNode = new Node(500);
    list->PushFront(PushNode);
    PushNode = new Node(500);
    list->PushFront(PushNode);
    list->Display();

    list->PopBack();
    list->Display();

    list->Remove(500);
    list->Display();

    list->Remove(100);
    list->Display();

    list->Erase(5);
    list->Erase(2);
    list->Display();

    SafeDelete(list);

    return 0;
}
