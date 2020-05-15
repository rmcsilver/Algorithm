/*
 * Program : Hash Table
 * File : hash_table.cpp
 * Description : Hash Table Based C++
 * Author : silver
 * Notes : 
 * Revision : 2020-05-14 Create
 *            2020-05-15 Chaning Hash Table
 */
#include <iostream>
#include <string.h>


struct Bucket
{
    std::string Key;
    int Value;
    Bucket()
    {
        Key = "";
        Value = 0;
    }
};

Bucket HashTable[10];

int HashFunction(std::string InKey)
{
    return (int)(InKey.at(0)) % 10;
}

void SaveData(std::string InKey, int InValue)
{
    int HashAddress = HashFunction(InKey);
    if(HashTable[HashAddress].Key != "" )
    {
        int size = (int)(sizeof(HashTable)/sizeof(Bucket));
        for(int i=HashAddress; i<size; ++i)
        {
            if(HashTable[i].Key == "")
            {
                HashTable[i].Key = InKey;
                HashTable[i].Value = InValue;
                return;
            }
            else if(HashTable[i].Key == InKey)
            {
                 HashTable[i].Value = InValue;
            }
        }
    }
    else
    {
        HashTable[HashAddress].Key = InKey;
        HashTable[HashAddress].Value = InValue;
    }
}

int GetData(std::string InKey)
{
    int HashAddress = HashFunction(InKey);
    if(HashTable[HashAddress].Key != "")
    {
        int size = sizeof(HashTable)/sizeof(Bucket);
        for(int i=HashAddress; i<size; ++i)
        {
            if(HashTable[i].Key == "")   return -1;
            else if(HashTable[i].Key == InKey)  return HashTable[i].Value;
        }
    }
        
    return -1;
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

    char Name01[10] = "aa";
    char Name02[10] = "ab";
    char Name03[10] = "ac";

    std::cout << HashFunction(Name01) << std::endl;
    std::cout << HashFunction(Name02) << std::endl;
    std::cout << HashFunction(Name03) << std::endl;

    SaveData(Name01, 1234);
    SaveData(Name02, 4321);
    SaveData(Name03, 5678);

    std::cout << GetData(Name01) << std::endl;
    std::cout << GetData(Name02) << std::endl;
    std::cout << GetData(Name03) << std::endl;

    return 0;
}
