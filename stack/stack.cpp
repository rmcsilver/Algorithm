#include <iostream>

class Stack
{
    private:
        int * DataList;
        int CurrentIndex;
        int Length;

    public:
        Stack(int InLength = 0);
        ~Stack();
        bool IsEmpty();
        int GetSize();
        bool PushData(int InData);
        int PopData();
        void PrintData();
};

Stack::Stack(int InLength)
{
    DataList = new int[InLength];
    Length = InLength;
    CurrentIndex = 0;
}

Stack::~Stack()
{
    delete [] DataList;
    DataList = nullptr;
}

bool Stack::IsEmpty()
{
    return CurrentIndex == 0;
}

int Stack::GetSize()
{
    return CurrentIndex;
}

bool Stack::PushData(int InData)
{
    if(this->GetSize() >= Length)
    {
        std::cout << "스택이 가득 찼습니다." << std::endl;
        return false;
    }

    DataList[CurrentIndex] = InData;
    CurrentIndex += 1;
    return true;
}

int Stack::PopData()
{
    if(this->GetSize() == 0)
    {
        std::cout << "데이터가 없습니다." << std::endl;
        return -1;
    }

    CurrentIndex -= 1;
    int OutData = DataList[CurrentIndex];
    return OutData;
}

void Stack::PrintData()
{
    for(int i=0; i<this->GetSize(); ++i)
    {
        std::cout << i << "번째 데이터 : " << DataList[i] << std::endl;
    }
}

int main()
{
    Stack StackList(10);

    std::cout << "스택 사이즈 : " << StackList.GetSize() << std::endl;
    for(int i=0; i<15; ++i)
    {
        StackList.PushData(i);
    }

    StackList.PrintData();
    std::cout << "스택 사이즈 : " << StackList.GetSize() << std::endl;

    for(int j=0; j<3; ++j)
    {
        StackList.PopData();
    }

    StackList.PrintData();
    std::cout << "스택 사이즈 : " << StackList.GetSize() << std::endl;
}
