/*
 * Program : Hash Table
 * File : hash_table.cpp
 * Description : Hash Table Based C++
 * Author : silver
 * Notes : 
 * Revision : 2020-05-14 Create
 */
#include <iostream>
#include <string.h>


struct Node
{
    std::string Key;
    int Data;
    Node * PrevNode;
    Node * NextNode;
    Node(std::string InKey=nullptr, int InData=0)
    {
        Key = InKey;
        Data = InData;
        PrevNode = nullptr;
        NextNode = nullptr;
    }
};


void SafeDelete(Node * InNode)
{
    if(InNode != nullptr)
    {
        delete InNode;
        InNode = nullptr;
    }
}


class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    int Size();
    bool IsEmpty();

    bool PushBack(Node * InElement);
    bool PopBack();

    Node * GetNode(std::string InKey);

private:
    Node * HeadNode;
    Node * TailNode;
    int ElementCount;
};

LinkedList::LinkedList()
{
    HeadNode = nullptr;
    TailNode = nullptr;
    ElementCount = 0;
}

LinkedList::~LinkedList()
{
    for(int i=0; i<ElementCount; ++i) 
    {
        PopBack();
    }
}

int LinkedList::Size()
{
    return ElementCount;
}

bool LinkedList::IsEmpty()
{
    if(HeadNode == nullptr || ElementCount == 0)
    {
        return true;
    }

    return false;
}

bool LinkedList::PushBack(Node * InElement)
{
    if(InElement == nullptr)
    {
        return false;
    }

    if(HeadNode == TailNode)
    {
        HeadNode = InElement;
        TailNode = HeadNode;
        HeadNode->PrevNode = TailNode;
        TailNode->NextNode = HeadNode;
        ElementCount++;
    }
    else
    {
        Node * CurrentNode = TailNode;
        CurrentNode->NextNode = InElement;
        TailNode = InElement;
        HeadNode->PrevNode = TailNode;
        TailNode->NextNode = HeadNode;
        ElementCount++;
    }

    return true;
}

bool LinkedList::PopBack()
{
    if(IsEmpty())
    {
        return false;
    }

    Node * CurrentNode = TailNode;
    if(HeadNode == TailNode)
    {
        HeadNode = nullptr;
        TailNode = nullptr;
        SafeDelete(CurrentNode);
    }
    else
    {
        TailNode = CurrentNode->PrevNode;
        HeadNode->PrevNode = TailNode;
        TailNode->NextNode = HeadNode;
        SafeDelete(CurrentNode);
    }

    return true;
}

Node * LinkedList::GetNode(std::string InKey)
{
    if(IsEmpty())
    {
        return nullptr;
    }

    Node * CurrentNode = HeadNode;
    do
    {
        if(CurrentNode->Key == InKey)    return CurrentNode;
        CurrentNode = CurrentNode->NextNode;
    }while(CurrentNode != HeadNode);

    return nullptr;
}

LinkedList HashTable[10];

int HashFunction(std::string InKey)
{
    return (int)(InKey.at(0)) % 10;
}

void StorageValue(std::string InKey, int InValue)
{
    int HashAddress = HashFunction(InKey);
    Node * NewNode = new Node(InKey, InValue);
    HashTable[HashAddress].PushBack(NewNode);
}

int GetData(std::string InKey)
{
    int HashAddress = HashFunction(InKey);
    Node * NewNode = HashTable[HashAddress].GetNode(InKey);
    return NewNode->Data;
}

int main()
{
    /*
    LinkedList * list = new LinkedList();
 
    Node * NewNode = new Node("Dave", 1234);
    list->PushBack(NewNode);

    Node * FindNode = list->GetNode("Dave");
    if(FindNode != nullptr)
    {
        std::cout << FindNode->Key << std::endl;
        std::cout << FindNode->Data << std::endl;
    }

    delete list;
    */

    char Name01[10] = "Andy";
    char Name02[10] = "Dave";
    char Name03[10] = "Jones";

    std::cout << HashFunction(Name01) << std::endl;
    std::cout << HashFunction(Name02) << std::endl;
    std::cout << HashFunction(Name03) << std::endl;

    StorageValue(Name01, 1234);
    StorageValue(Name02, 4321);
    StorageValue(Name03, 5678);

    std::cout << GetData(Name01) << std::endl;
    std::cout << GetData(Name02) << std::endl;


    return 0;
}
