#include <iostream>

using namespace std;

const int MAX_LENGTH = 256;

class Queue{
private:
    int DataList[MAX_LENGTH];
    int FrontIndex;
    int BackIndex;

public:
    Queue();
    bool IsEmpty();
    void PushData(int InData);
    int PopData();
    int GetSize();
};

Queue::Queue(){
    FrontIndex = 0;
    BackIndex = 0;
}

bool Queue::IsEmpty(){
    return FrontIndex == BackIndex;
}

void Queue::PushData(int InData){
    DataList[BackIndex] = InData;
    BackIndex += 1;
}

int Queue::PopData(){
    int OutData = DataList[FrontIndex];
    FrontIndex += 1;
    return OutData;
}

int Queue::GetSize(){
    return BackIndex - FrontIndex;
}

int main(){
    
    Queue QueueList;

    std::cout << "큐의 현재 사이즈 :" << QueueList.GetSize() << endl; 

    for(int i=0; i<10; i++)
    {
        QueueList.PushData(i);
        std::cout << "push() : " << i << endl;
    }

    std::cout << "큐의 현재 사이즈 :" << QueueList.GetSize() << endl; 

    for(int j=0; j<5; j++)
    {
        std::cout << "pop() : " << QueueList.PopData() << endl;
    }

    std::cout << "큐의 현재 사이즈 :" << QueueList.GetSize() << endl; 

}
