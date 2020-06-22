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
    
    std::cout << ReplaceAll(text, "l", "r") << "개 변경" << std::endl;

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
   
    std::cout << "중간 점검" << std::endl;

    std::string::iterator iter = text.begin();
    if(find.size() == 1)
    {
        for(; iter != text.end(); iter++)
        {
            if(*iter == find[0])
            {
                text[index] = replace[0];
                count++;
            }
            index++;
        }
    }
    else
    {

    }

    std::cout << "count : " << count << std::endl;

    return count;
}
