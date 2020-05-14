/*
 *
 *
 *
 */
#include <iostream>


int HashTable[10];

int HashFunction(char * InKey)
{
    return (int)(InKey[0]) % 5;
}

void StorageValue(char* InKey, int InValue)
{
    int HashAddress = HashFunction(InKey);
    HashTable[HashAddress] = InValue;
}

int GetData(char * InKey)
{
    int HashAddress = HashFunction(InKey);
    return HashTable[HashAddress];
}

int main()
{
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
