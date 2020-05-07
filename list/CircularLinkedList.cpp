/*
 * Program : Circular Linked List
 * File : list.cpp
 * Description : Circular Double Linked List Base C++
 * Author : silver
 * Note :
 * Revisions : 2020/05/07
 */

#include <iostream>

struct Node
{
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

class CircularLinkedList
{
public:
    CircularLinkedList();
    ~CircularLinkedList();
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

void SafeDelete(CircularLinkedList * InList)
{
    if(InList)
    {
        delete InList;
        InList = nullptr;
    }
}

CircularLinkedList::CircularLinkedList()
{
    HeadNode = nullptr;
    TailNode = nullptr;
    ElementCount = 0;
}

CircularLinkedList::~CircularLinkedList()
{
    if(!IsEmpty())
    {
        Node * CurrentNode = HeadNode;
        do
        {
            Node * DeleteNode = CurrentNode;
            CurrentNode = CurrentNode->NextNode;
            SafeDelete(DeleteNode);
        }while(CurrentNode != HeadNode);
    }

    SafeDelete(HeadNode);
    SafeDelete(TailNode);
}

int CircularLinkedList::Size()
{
    return ElementCount;
}

bool CircularLinkedList::IsEmpty()
{
    return (HeadNode == nullptr || ElementCount == 0);
}

void CircularLinkedList::Display()
{
    if(IsEmpty())
    {
        std::cout << "출력할 데이터가 없습니다." << std::endl;
        return;
    }

    std::cout << "[Head]->";
    Node * CurrentNode = HeadNode;
    do
    {
        std::cout << "[" << CurrentNode->Data << "]->";
        CurrentNode = CurrentNode->NextNode;
    }while(CurrentNode != HeadNode);

    std::cout << "[Tail]" << std::endl;
    std::cout << "현재 리스트의 사이즈는 " << Size() << " 입니다.\n" << std::endl;
}

bool CircularLinkedList::PushBack(Node * InElement)
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

    TailNode->NextNode = HeadNode;
    HeadNode->PrevNode = TailNode;
    
    ElementCount++;

    return true;
}

bool CircularLinkedList::PushFront(Node * InElement)
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
        Node * CurrentNode = HeadNode;
        CurrentNode->PrevNode = InElement;
        InElement->NextNode = CurrentNode;
        HeadNode = InElement;
    }

    HeadNode->PrevNode = TailNode; 
    TailNode->NextNode = HeadNode;

    ElementCount++;

    return true;
}

bool CircularLinkedList::PopBack()
{
    if(IsEmpty())
    {
        std::cout << "데이터가 없습니다." << std::endl;
        return false;
    }

    Node * PopNode = TailNode;
    TailNode = PopNode ->PrevNode;
    TailNode->NextNode = HeadNode;
    HeadNode->PrevNode = TailNode;
    SafeDelete(PopNode);

    ElementCount--;
    return true;
}

bool CircularLinkedList::PopFront()
{
    if(IsEmpty())
    {
        std::cout << "데이터가 없습니다." << std::endl;
        return false;
    }

    Node * PopNode = HeadNode;
    HeadNode = PopNode->NextNode;
    HeadNode->PrevNode = TailNode;
    TailNode->NextNode = HeadNode;
    SafeDelete(PopNode);

    ElementCount--;

    return true;
}

bool CircularLinkedList::Remove(int InValue)
{
    if(IsEmpty())
    {
        std::cout << "삭제할 데이터가 없습니다." << std::endl;
        return false;
    }

    bool Result = false;
    Node * CurrentNode = HeadNode;
    
    if(CurrentNode->Data == InValue && CurrentNode == HeadNode)
    {
        HeadNode = CurrentNode->NextNode;
        HeadNode->PrevNode = TailNode;
        TailNode->NextNode = HeadNode;
        SafeDelete(CurrentNode);
        CurrentNode = HeadNode;
        ElementCount--;
        Result = true;
    }

    do
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
                TailNode->NextNode = HeadNode;
                HeadNode->PrevNode = TailNode;
                SafeDelete(CurrentNode);
                ElementCount--;
                return true;
            }

            CurrentNode->PrevNode->NextNode = CurrentNode->NextNode;
            CurrentNode->NextNode->PrevNode = CurrentNode->PrevNode;
            Node * TempNode = CurrentNode->NextNode;
            ElementCount--;
            CurrentNode = TempNode;
            Result = true;
        }
        else
        {
            CurrentNode = CurrentNode->NextNode;
        }
    }while(CurrentNode != HeadNode);

    return Result;
}

bool CircularLinkedList::Erase(int InPosition)
{
    if(IsEmpty())
    {
        std::cout << "삭제할 데이터가 없습니다." << std::endl;
        return false;
    }

    if(InPosition > Size())
    {
        std::cout << "입력한 위치에 데이터가 없습니다." << std::endl;
        return false;
    }

    int Position = 0;
    Node * CurrentNode = HeadNode;
    do
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
                TailNode->NextNode = HeadNode;
                HeadNode->PrevNode = TailNode;
            }
            else
            {
                CurrentNode->PrevNode->NextNode = CurrentNode->NextNode;
                CurrentNode->NextNode->PrevNode = CurrentNode->PrevNode;
            }

            SafeDelete(CurrentNode);
            ElementCount--;
            return true;
        }

        CurrentNode = CurrentNode->NextNode;

    }while(CurrentNode != HeadNode);

    return false;
}

bool CircularLinkedList::Erase(int InBeginPosition, int InEndPosition)
{
    return false;
}


int main()
{
    CircularLinkedList * list = new CircularLinkedList();

    list->Display();

    Node * PushNode = nullptr;

    PushNode = new Node(100);
    list->PushBack(PushNode);
    list->Display();

    PushNode = new Node(200);
    list->PushFront(PushNode);
    list->Display();

    PushNode = new Node(500);
    list->PushBack(PushNode);
    list->Display();

    list->PopFront();
    list->Display();

    list->PopBack();
    list->PopBack();
    list->Display();

    for(int i=0; i<10; ++i)
    {
        PushNode = new Node(i);
        list->PushBack(PushNode);
    }
    list->Display();

    PushNode = new Node(9);
    list->PushFront(PushNode);
    list->Display();

    list->Remove(9);
    list->Display();

    list->Erase(5);
    list->Display();

    SafeDelete(list);
    /*
    CircularLinkedList linkedlist;
    
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;

    linkedlist.Push(1);
    linkedlist.PrintList();
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;

    linkedlist.Push(10);
    linkedlist.Push(20);
    linkedlist.PrintList();
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;

    linkedlist.InsertBefore(5, 20);
    linkedlist.PrintList();
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;

    linkedlist.DeleteData(10);
    linkedlist.PrintList();
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;

    linkedlist.DeleteData(5);
    linkedlist.PrintList();
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;

    Node * FindNode = nullptr;

    FindNode = linkedlist.SearchData(20);
    if(FindNode)
    {
        std::cout << FindNode << std::endl;
    }
    else
    {
        std::cout << "데이터 찾기 실패" << std::endl;
    }   
    
    FindNode = linkedlist.SearchData_From_Tail(20);
    if(FindNode)
    {
        std::cout << FindNode << std::endl;
    }   
    else
    {
        std::cout << "데이터 찾기 실패" << std::endl;
    }

    FindNode = linkedlist.SearchData(10);
    if(FindNode)
    {
        std::cout << FindNode << std::endl;
    }   
    else
    {
        std::cout << "데이터 찾기 실패" << std::endl;
    }

    FindNode = linkedlist.SearchData(10);
    if(FindNode)
    {
        std::cout << FindNode << std::endl;
    }   
    else
    {
        std::cout << "데이터 찾기 실패" << std::endl;
    }
*/
    /*
    linkedlist.SearchData(10);

    linkedlist.DeleteData(10);
    linkedlist.PrintList();
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;


    linkedlist.DeleteData(20);
    linkedlist.PrintList();
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;
*/

    return 0;
}
