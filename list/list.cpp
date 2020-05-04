#include <iostream>

struct Node
{
    Node * PrevNode;
    Node * NextNode;
    int Data;
    Node(int InData=0)
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

class LinkedList
{
    private:
        Node * HeadNode;
        Node * TailNode;
        int ElementCount;

    public:
        LinkedList();
        ~LinkedList();
        int GetSize();
        void InsertData(int InData);
        bool InsertBefore(int InData, int InBeforeData);
        bool DeleteData(int InData);
        Node * SearchData(int InData);
        Node * SearchData_From_Tail(int InData);
        void PrintList();
};

LinkedList::LinkedList()
{
    HeadNode = nullptr;
    TailNode = nullptr;
    ElementCount = 0;
}

LinkedList::~LinkedList()
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
        TailNode = nullptr;
    }

    HeadNode = nullptr;
}

int LinkedList::GetSize()
{
    return ElementCount;
}

void LinkedList::PrintList()
{
    int CurrentIndex = 0;
    Node* TempNode = HeadNode;
    while (TempNode)
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
        Node * InsertNode = new Node(InData);
        HeadNode = InsertNode;
        TailNode = HeadNode;
    }
    else
    {
        Node * InsertNode = new Node(InData);
        
        Node * TempNode = this->TailNode;
        TempNode->NextNode = InsertNode;
        InsertNode->PrevNode = TempNode;
        this->TailNode = InsertNode;
    }

    ElementCount++;
}
  
bool LinkedList::InsertBefore(int InData, int InBeforeData)
{
    if(HeadNode == nullptr)
    {
        std::cout << "BeforeData를 찾을수 없습니다." << std::endl;
        return false;
    }
    else
    {
        Node * TempNode = TailNode;
        if(TempNode == nullptr) return false;
        while(TempNode->Data != InBeforeData)
        {
            TempNode = TempNode->PrevNode;
        }

        Node * NewNode = new Node(InData);
        Node * TempPrevNode = TempNode->PrevNode;
        TempPrevNode->NextNode = NewNode;
        NewNode->PrevNode = TempPrevNode;
        NewNode->NextNode = TempNode;
        TempNode->PrevNode = NewNode;
    }

    ElementCount++;
    return true;
}
   
bool LinkedList::DeleteData(int InData)
{
    if(HeadNode == nullptr && ElementCount == 0)
    {
        std::cout << "삭제할 데이터가 없습니다." << std::endl;
        return false;
    }
    else
    {
        if(HeadNode == TailNode)
        {
            Node * TempNode = HeadNode;
            if(TempNode->Data == InData)
            {
                SafeDelete(TempNode);
                HeadNode = nullptr;
                TailNode = nullptr;
                ElementCount--;
                return true;
            }
        }
        else
        {
            Node * TempNode = HeadNode;
            if(TempNode->Data == InData)
            {
                HeadNode = TempNode->NextNode;
                TempNode->PrevNode = nullptr;
                SafeDelete(TempNode);
                ElementCount--;
                return true;
            }

            while(TempNode)
            {
                if(TempNode->Data == InData)
                {
                    TempNode->PrevNode->NextNode = TempNode->NextNode;
                    TempNode->NextNode->PrevNode = TempNode->PrevNode;
                    if(TempNode->NextNode->NextNode == nullptr)
                    {
                        TailNode = TempNode->NextNode;
                    }
                    SafeDelete(TempNode);
                    ElementCount--;
                    return true;    
                }
                TempNode = TempNode->NextNode;
            }
        }
    }

    std::cout << InData << " 데이터 삭제 실패" << std::endl;
    return false;
}

Node * LinkedList::SearchData(int InData)
{
    if(HeadNode == nullptr)
    {
        std::cout << "검색할 데이터가 없습니다." << std::endl;
        return nullptr;
    }
    
    int LocalIndex = 1;
    Node* TempNode = HeadNode;
    while(TempNode)
    {
        if(TempNode->Data == InData)
        {
            std::cout << InData << "는 앞에서 " << LocalIndex << "번째 데이터 입니다." << std::endl;
            return TempNode;
        }
        TempNode = TempNode->NextNode;
        LocalIndex += 1;
    }
    
    return nullptr;
}
 
Node * LinkedList::SearchData_From_Tail(int InData)
{
    if(TailNode == nullptr || ElementCount == 0)
    {
        std::cout << "검색할 데이터가 없습니다." << std::endl;
        return nullptr;
    }

    int LocalIndex = 1;
    Node * TempNode = TailNode;
    while(TempNode)
    {
        if(TempNode->Data == InData)
        {
            std::cout << InData << "는 뒤에서 " << LocalIndex << "번째 데이터 입니다." << std::endl;
            return TempNode;
        }

        TempNode = TempNode->PrevNode;
        LocalIndex += 1;
    }

    return nullptr;
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

    linkedlist.InsertBefore(5, 20);
    linkedlist.PrintList();
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;


    linkedlist.DeleteData(10);
    linkedlist.PrintList();
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;

    linkedlist.DeleteData(5);
    linkedlist.PrintList();
    std::cout << "링크드리스트 사이즈 : " << linkedlist.GetSize() << std::endl;

    Node * FindNode = linkedlist.SearchData(20);
    if(FindNode)
    {
        std::cout << FindNode << std::endl;
    }   
    else
    {
        std::cout << "데이터 찾기 실패" << std::endl;
    }

    Node * FindNode2 = linkedlist.SearchData_From_Tail(20);
    if(FindNode2)
    {
        std::cout << FindNode2 << std::endl;
    }   
    else
    {
        std::cout << "데이터 찾기 실패" << std::endl;
    }


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
