/*
 * Program : Hash Table
 * File : hash_table.cpp
 * Description : Hash Table Based C++
 * Author : silver
 * Notes : 
 * Revision : 2020-05-14 Create
 *            2020-05-15 Chaning Hash Table
 *            2020-06-01 Modified 
 */

#include <iostream>
#include <string.h>
#include <string>


struct data
{
    std::string key;
    std::string value;
    data(std::string InKey="", std::string InValue="")
    {
        key = InKey;
        value = InValue;
    }
    bool IsEmpty()
    {
        return (key == "" && value == "")? true: false;  
    }
};

void SafeDelete(data * InDataList)
{
    if(InDataList)
    {
        delete[] InDataList;
        InDataList = nullptr;
    }
}

class HashTable
{
public:
    HashTable(int InSize=13);
    ~HashTable();
    int hash(std::string InKey);
    int hash_horner(std::string InKey);
    int hash_shift(std::string InKey);
    void add(std::string InKey, std::string InValue);
    void add_internal(std::string InKey, std::string InValue, data * InTable, int InSize, bool resizing=false);
    bool resize();
    int getSize(){return size;}
    data * getData(int index);

private:
    int size;
    data * table;
    int entry_count;
};


HashTable::HashTable(int InSize)
{
    size = InSize;
    table = new data[size];
    entry_count = 0;
}

HashTable::~HashTable()
{
    SafeDelete(table);
}

int HashTable::hash(std::string InKey)
{
    int sum = 0;
    int length = InKey.length();
    for(int i=0; i<length; ++i)
    {
        sum += InKey[i];
    }
    return sum % size;
}

int HashTable::hash_horner(std::string InKey)
{
    int sum = 0;
    int length = InKey.length();
    int primeNum = 13;
    for(int i=0; i<length; ++i)
    {
        sum += sum * primeNum + InKey[i];
    }
    return sum % size;
}

int HashTable::hash_shift(std::string InKey)
{
    int sum = 0;
    int length = InKey.length();
    for(int i=0; i<length; ++i)
    {
        sum += (sum << 4) + InKey[i];
    }

    return sum % size;
}

void HashTable::add(std::string InKey, std::string InValue)
{
    add_internal(InKey, InValue, this->table, this->size);
}

void HashTable::add_internal(std::string InKey, std::string InValue, data * InTable, int InSize, bool resizing)
{
    int index = hash(InKey);
    if(InTable[index].IsEmpty())
    {
        InTable[index].key = InKey;
        InTable[index].value = InValue;

        std::cout << "debug #1 table[" << index << "] key = " << InTable[index].key << std::endl;
    }
    else
    {
        bool result = false;
        int attempt_count = 0;
        while(result == false)
        {
            index = (hash_horner(InKey) + attempt_count) % InSize;
            if(table[index].IsEmpty())
            {
                InTable[index].key = InKey;
                InTable[index].value = InValue;
                result = true;
            }
            else attempt_count++;
        }
    
        std::cout << "debug #2 table[" << index << "] key = " << InTable[index].key << std::endl;
    }


    if(resizing == false)
    {
        this->entry_count++;

        //std::cout << "entry_count = " << entry_count << std::endl;
        //std::cout << "size * 0.7 = " << InSize * 0.7 << std::endl;
            
        if(this->entry_count > InSize * 0.7)
        {
            std::cout << "resize" << std::endl;
            resize();
        }
    }
    
}


bool HashTable::resize()
{
    bool result = false;
    int new_size = 0;
    new_size = size * 2;
    data * new_table = new data[new_size];
    
    std::cout << std::endl;

    for(int i=0; i<size; ++i)
    {
        if(table[i].IsEmpty() == false)
        {
            add_internal(table[i].key, table[i].value, new_table, new_size, true);
            std::cout << "debug resize key : " << table[i].key << std::endl;
        }

    }
    size = new_size;
    table = new_table;

    return result;
}

data * HashTable::getData(int index)
{
    if(index > size -1) return nullptr;

    return &table[index];
}

void Print(HashTable * hash)
{
    if(hash != nullptr)
    {
        for(int i=0; i<(int)hash->getSize(); ++i)
        {
            data * data = hash->getData(i);
            if(data != nullptr)
            {
                std::cout << "[" << i << "]" << data->key;
                std::cout << ", value = " << data->value << std::endl;
            }
        }

        std::cout << std::endl;
    }
}


int main()
{
    HashTable * hash = new HashTable(5);
    hash->add("Andy", "01Ta0123");
    Print(hash);

    hash->add("bred", "1004Troy");
    hash->add("Tom", "andToms666");
    hash->add("Neyo", "becauseofyou");
    hash->add("oscar", "mike");
    
    Print(hash);

    delete hash;

    return 0;
}
