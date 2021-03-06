/*
    K번째 수
    배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.

    예를 들어 array가 [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면

    array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다. 1에서 나온 배열을 정렬하면 [2, 3, 5, 6]입니다. 2에서 나온 배열의 3번째 숫자는 5입니다. 배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 매개변수로 주어질 때, commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

    제한사항 array의 길이는 1 이상 100 이하입니다. array의 각 원소는 1 이상 100 이하입니다. commands의 길이는 1 이상 50 이하입니다. commands의 각 원소는 길이가 3입니다.
    
    int array[] = { 1, 5, 2, 6, 3, 7, 4  };
    int commands[][3] = { { 2, 5, 3  },
                          { 4, 4, 1  },
                        { 1, 7, 3  } };
 */

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int array[] = { 1, 5, 2, 6, 3, 7, 4  };
int commands[][3] = { { 2, 5, 3  },
                      { 4, 4, 1  },
                      { 1, 7, 3  } };


int * solution(std::vector<int> & array, std::vector<int> & commands)
{
    int * result = new int[commands.size()/3];
    for(int index=0; index<commands.size()/3; ++index)
    {
        int i = commands[index*3 + 0] - 1;
        int j = commands[index*3 + 1] - 1;
        int k = commands[index*3 + 2] - 1;

        std::vector<int> temp;
        std::copy(array.begin()+i, array.begin()+j+1, std::back_inserter(temp));
        std::sort(temp.begin(), temp.end());
        result[index] = temp[k];
    }

    return result;
}

int main()
{
    int n = sizeof(array) / sizeof(array[0]);
    int n2 = sizeof(commands) / sizeof(commands[0][0]); 
    std::vector<int> newArray(array, array + n);
    std::vector<int> newCommands(commands[0], commands[0] + n2);
    
    int * result = solution(newArray, newCommands);
    for(int i=0;i<sizeof(result)/sizeof(result[0])+1; ++i)
    {
        std::cout << "[" << i + 1 << "] -> " << result[i] << std::endl;  
    }
    
    return 0;
}

/*
int findK(int InArray[], int InArraySize, int InCommands[][3], int InCommandsSize, std::vector<int> &out)
{
    // 예외처리
    if(InArraySize < 1 || InArraySize > 100)    return 1;
    else if(InCommandsSize < 1 ||InCommandsSize > 50)    return 2;
    else if(InCommandsSize % 3 != 0)   return 3;
    else
    {
        for(int i: array)
        {
            if(i < 1 || i > 100)    return 4;
        }
    }

    out.clear();
    int commandSize = InCommandsSize / 3;
    for(int i=0; i<commandSize; ++i)
    {
        int begin = InCommands[i][0] - 1;
        int end = InCommands[i][1] - 1;
        int position = InCommands[i][2] - 1;   
        //std::cout << begin << " " << end << " " << position << std::endl;
        
        int size = end - begin + 1; 
        std::vector<int> data(size);          
        std::copy(InArray + begin, InArray+end+1, data.begin());

        std::sort(data.begin(), data.end());
        //for(int j: data) std::cout << j << " ";
        //std::cout << std::endl;
        
        int number = data.at(position);
        //std::cout << number << " ";
        
        out.push_back(number);
    }

    return 0;
}

int main()
{
    int arraySize = sizeof(array) / sizeof(array[0]);
    int commandsSize = sizeof(commands) / sizeof(commands[0][0]);
    std::vector<int> resultData(50, 0);
    int resultCode =  findK(array, arraySize, commands, commandsSize, resultData);

    if(resultCode == 0)
    {
        for(int i: resultData)
        {
            std::cout << i << " ";
        }
    }
    else
    {
        switch(resultCode)
        {
            case 1:
                std::cout << "에러 : 데이터의 갯수가 잘못 되었습니다." << std::endl;
                break;
            case 2:
                std::cout << "에러 : 명령어의 갯수가 잘못 되었습니다." << std::endl;
                break;
            case 3:
                std::cout << "에러 : 기본 명령어의 갯수가 3개가 아닙니다." << std::endl;
                break;
            default:
                std::cout << "에러 : 데이터 숫자의 범위가 벗어났습니다." << std::endl;
                break;
        }
    }

    return 0;
}
*/
