#include <algorithm>
#include <iostream>
#include <unordered_map>

int main()
{
    int numbers[] = { 7,3,6,4,-1,2,5,8,1,10 };
    int sum = 9;

    auto v = std::unordered_map<int, int>();
    
    for (int num: numbers)
    {
        auto iter = v.find(num);
        if (iter != v.end()) std::cout << iter->second << ", " << num << std::endl;
        else v[sum-num] = num;
    }
    
    return 0;
}