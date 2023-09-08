#include <algorithm>
#include <iostream>
#include <unordered_map>

int a() { return 1;}
int b() { return 2;}
int (*arr[]) () = {a, b};

int main()
{
    std::cout << arr[0]() << arr[1]() << std::endl;
    return 0;
}