#include <iostream>

using namespace std;

const int MAX_LENGTH = 256;

class Stack{
    private:
        int DataList[MAX_LENGTH];
        int CurrentIndex;

    public:
        Stack();
        bool IsEmpty();
        int GetSize();
        void PushData(int InData);
        int PopData();
};

Stack::Stack(){
    CurrentIndex = 0;
}

bool Stack::IsEmpty(){
    return CurrentIndex == 0;
}

int Stack::GetSize(){
    return CurrentIndex;
}

void Stack::PushData(int InData){
    DataList[CurrentIndex] = InData;
    CurrentIndex += 1;
}

int Stack::PopData(){
    CurrentIndex -= 1;
    int OutData = DataList[CurrentIndex];
    return OutData;
}

int main(){
    Stack StackList;

    cout << "스택 사이즈 : " << StackList.GetSize() << endl;
    for(int i=0; i<5; i++)
    {
        StackList.PushData(i);
        cout << "push() : " << i << endl;
    }

    cout << "스택 사이즈 : " << StackList.GetSize() << endl;

    for(int j=0; j<3; j++)
    {
        cout << "pop() : " << StackList.PopData() << endl;
    }

    cout << "스택 사이즈 : " << StackList.GetSize() << endl;
}
