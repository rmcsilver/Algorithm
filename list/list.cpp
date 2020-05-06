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
        void PrintList();
        void Push(int InData);
        bool InsertBefore(int InData, int InBeforeData);
        bool DeleteData(int InData);
        Node * SearchData(int InData);
        Node * SearchData_From_Tail(int InData);
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
    Node* TempNode = this->HeadNode;
    do
    {
        CurrentIndex += 1;
        std::cout << CurrentIndex << "번째 데이터 : " << TempNode->Data << std::endl;
        TempNode = TempNode->NextNode;
    }while(TempNode != this->HeadNode);
}

void LinkedList::Push(int InData)
{
    if(HeadNode == nullptr)
    {
        Node * InsertNode = new Node(InData);
        this->HeadNode = InsertNode;
        this->TailNode = this->HeadNode;
        this->HeadNode->PrevNode = this->TailNode;
        this->TailNode->NextNode = this->HeadNode;
    }
    else
    {
        Node * InsertNode = new Node(InData); 
        Node * TempNode = this->TailNode;
        TempNode->NextNode = InsertNode;
        InsertNode->PrevNode = TempNode;
        this->TailNode = InsertNode;
        this->HeadNode->PrevNode = this->TailNode;
        this->TailNode->NextNode = this->HeadNode;
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
        Node * BeforeNode = this->TailNode;
        while(BeforeNode->Data != InBeforeData)
        {
            BeforeNode = BeforeNode->PrevNode;
        }

        Node * InsertNode = new Node(InData);
        if(BeforeNode != this->HeadNode)
        {
            BeforeNode->PrevNode->NextNode = InsertNode;
            InsertNode->PrevNode = BeforeNode->PrevNode;
        }
        else
        {
            this->HeadNode = InsertNode;
            this->HeadNode->PrevNode = this->TailNode;
            this->TailNode->NextNode = this->HeadNode;
        }

        BeforeNode->PrevNode = InsertNode;
        InsertNode->NextNode = BeforeNode;
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
        if(HeadNode == this->TailNode)
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
            Node * TempNode = this->HeadNode;
            if(TempNode->Data == InData)
            {
                this->HeadNode = TempNode->NextNode;
                this->HeadNode->PrevNode = this->TailNode;
                SafeDelete(TempNode);
                ElementCount--;
                return true;
            }

            while(TempNode)
            {
                if(TempNode->Data == InData)
                {
                    if(TempNode != this->TailNode)
                    {
                        TempNode->PrevNode->NextNode = TempNode->NextNode;
                        TempNode->NextNode->PrevNode = TempNode->PrevNode;
                    }
                    else
                    {
                        this->TailNode = TempNode->PrevNode;
                        this->TailNode->NextNode = this->HeadNode;
                    }
                    SafeDelete(TempNode);
                    ElementCount--;
                    return true;    
                }

                TempNode = TempNode->NextNode;
            }
        }
    }

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
    Node* FindNode = this->HeadNode;
    do
    {
        if(FindNode->Data == InData)
        {
            std::cout << InData << "는 앞에서 " << LocalIndex << "번째 데이터 입니다." << std::endl;
            return FindNode;
        }

        FindNode = FindNode->NextNode;
        LocalIndex += 1;
    }while(FindNode != this->HeadNode);
    
    return nullptr;
}
 
Node * LinkedList::SearchData_From_Tail(int InData)
{
    if(TailNode == nullptr || ElementCount == 0)
    {
        return nullptr;
    }

    int LocalIndex = 1;
    Node * FindNode = this->TailNode;
    do
    {
        if(FindNode->Data == InData)
        {
            std::cout << InData << "는 뒤에서 " << LocalIndex << "번째 데이터 입니다." << std::endl;
            return FindNode;
        }

        FindNode = FindNode->PrevNode;
        LocalIndex += 1;
    }while(FindNode != this->HeadNode);

    return nullptr;
}
 

int main()
{
    LinkedList linkedlist;
    
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
