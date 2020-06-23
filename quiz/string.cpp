/*
 * Program : string
 * File : string.cpp
 * Description : string Base C++
 * Author : silver
 * Note :
 * Revisions : 2020/06/19
 */

#include <iostream>
#include <string>


std::string LTrim(const std::string &text);
std::string RTrim(const std::string &text);
std::string Trim(const std::string &text);
int ReplaceAll(std::string &text, const std::string &find, const std::string &replace); 


int main()
{
    std::string text = " Hello, World! ";
    std::cout << text << std::endl;
    std::cout << "text size : " << text.size() << std::endl;
    
    text = LTrim(text);
    std::cout << text << std::endl;
    std::cout << "text size : " << text.size() << std::endl;
    
    text = RTrim(text);
    std::cout << text << std::endl;
    std::cout << "text size : " << text.size() << std::endl;
    
    std::cout << ReplaceAll(text, " ", "$") << "개 변경" << std::endl;
    std::cout << ReplaceAll(text, "H", "W") << "개 변경" << std::endl;

    std::cout << text << std::endl;
    return 0;
}

std::string LTrim(const std::string &text)
{
    std::string out = text;
    std::string::iterator iter = out.begin();
    int index = 0;
    for(; iter != out.end(); iter++)
    {
        if(*iter != ' ') break;
        index++;
    }
    out = out.substr(index);
    return out;
}

std::string RTrim(const std::string &text)
{
    std::string out = text;
    std::string::reverse_iterator iter = out.rbegin();
    int index = 0;
    for(; iter != out.rend(); iter++)
    {
        if(*iter != ' ') break;
        index++;
    }
    out = out.substr(0, out.size()-index);
    return out;
}

std::string Trim(const std::string &text)
{
    std::string out = text;
    out = LTrim(out);
    out = RTrim(out);
    return out;
}

int ReplaceAll(std::string &text, const std::string &find, const std::string &replace)
{
    int index, count = 0;
    if(find.size() == 0 || replace.size() == 0)    return -1;

    std::size_t found = text.find(find);
    while(found != std::string::npos)
    {
        text.replace(found, find.size(), replace);
        count++;
        found = text.find(find, found+1);
    }

    return count;
}
