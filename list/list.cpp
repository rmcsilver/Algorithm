#include <iostream>

struct Node{
    Node* NextNode = nullptr;
    int Data;
};

class LinkedList
{
    private:
        Node* HeadNode;
        int ElementCount;

    public:
        LinkedList();
        ~LinkedList();
        int GetSize();
        void InsertData(int InData);
        bool DeleteData(int InData);
        int SearchData(int InData);
        void PrintList();
};

LinkedList::LinkedList()
{
    HeadNode = nullptr;
    ElementCount = 0;
}

LinkedList::~LinkedList()
{
    if(ElementCount == 0)
    {
        delete HeadNode;
    }
    else
    {
        for(int i=0; i<ElementCount; i++)
        {
            Node* TempNode = HeadNode;
            while(TempNode)
            {
                if(TempNode->NextNode == nullptr)
                {
                    delete TempNode;
                    break;
                }
                TempNode = TempNode->NextNode;
            }
        }
    }
}

int LinkedList::GetSize()
{
    return ElementCount;
}

void LinkedList::PrintList()
{
    int CurrentIndex = 0;
    Node* TempNode = HeadNode;
    while (TempNode != nullptr)
    {
        CurrentIndex += 1;
        std::cout << CurrentIndex << "번째 데이터 : " << TempNode->Data << std::endl;
        TempNode = TempNode->NextNode;
    }
}

void LinkedList::InsertData(int InData)
{
    if(HeadNode == nullptr)
    {
        HeadNode = new Node();
        HeadNode->Data = InData;
        ElementCount += 1;
        std::cout << "head 에 " << InData << "삽입" << std::endl;
    }
    else
    {
        Node* TempNode = HeadNode;
        while(TempNode != nullptr)
        {
            if(TempNode->NextNode == nullptr)
            {
                TempNode->NextNode = new Node();
                TempNode->NextNode->Data = InData;
                ElementCount += 1;
                std::cout << "next에 " << InData << " 삽입" << std::endl;
                return;
            }

            TempNode = TempNode->NextNode;
        }
    }
}
   
bool LinkedList::DeleteData(int InData)
{
    if(HeadNode == nullptr && ElementCount == 0)
    {
        std::cout << "삭제할 데이터가 없습니다." << std::endl;
        return false;
    }
    else{
        if(HeadNode->Data == InData)
        {
            Node* TempNode = HeadNode;
            HeadNode = HeadNode->NextNode;
            ElementCount -= 1;
            delete TempNode;
            std::cout << InData << " 데이터 삭제 완료" << std::endl;        
        }
        else
        {
            Node* TempNode2 = HeadNode;
            while(TempNode2 != nullptr)
            {
                if(TempNode2->NextNode->Data == InData)
                {
                    Node* TempNode3 = TempNode2->NextNode;
                    TempNode2->NextNode = TempNode2->NextNode->NextNode;
                    delete TempNode3;
                    ElementCount -= 1;
                    std::cout << InData << " 데이터 삭제 완료" << std::endl;
                    return true;
                }
                else{
                    TempNode2 = TempNode2->NextNode;
                }
            }
        }
    }

    return false;
}

int LinkedList::SearchData(int InData)
{
    if(HeadNode == nullptr)
    {
        std::cout << "찾으시는 데이터가 없습니다." << std::endl;
        return -1;
    }
    
    int LocalIndex = 1;
    Node* TempNode = HeadNode;
    while(TempNode)
    {
        if(TempNode->Data == InData)
        {
            std::cout << InData << "는 " << LocalIndex << "번째 데이터 입니다." << std::endl;
            return LocalIndex;
        }
        TempNode = TempNode->NextNode;
        LocalIndex += 1;
    }
    
    return -1;
}
 


int main()
{
    LinkedList linkedlist;
    
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;

    linkedlist.InsertData(1);
    linkedlist.PrintList();
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;


    linkedlist.InsertData(10);
    linkedlist.InsertData(20);
    linkedlist.PrintList();
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;

    linkedlist.SearchData(10);

    linkedlist.DeleteData(10);
    linkedlist.PrintList();
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;


    linkedlist.DeleteData(20);
    linkedlist.PrintList();
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;


    return 0;
}
