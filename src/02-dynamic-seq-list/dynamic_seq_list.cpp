#include <cstring>
#include <iostream>
#include "dynamic_seq_list.h"

void dynamic_seq_list::init(DSeqList &list)
{
    list.data = new ElemType[INIT_CAPACITY];
    list.length = 0;
    list.capacity = INIT_CAPACITY;
}

bool dynamic_seq_list::insert(DSeqList &list, int index, const ElemType &elem)
{
    if (index < 0 || index > list.length || list.capacity == 0) return false;
    if (list.length >= list.capacity)
    {
        // double expand
        auto new_data = new ElemType[list.capacity << 1];
        std::memcpy(new_data, list.data, list.capacity * sizeof(ElemType));

        delete[] list.data;

        list.data = new_data;
        list.capacity <<= 1;
    }

    for (int i = list.length; i > index; i--)
    {
        list.data[i] = list.data[i - 1];
    }

    list.data[index] = elem;
    list.length++;
    
    return true;
}

bool dynamic_seq_list::remove_at(DSeqList &list, int index)
{
    if (index < 0 || index >= list.length) return false;

    for (int i = index; i < list.length - 1; i++)
    {
        list.data[i] = list.data[i + 1];
    }

    list.length--;

    return true;
}

bool dynamic_seq_list::at(const DSeqList &list, int index, ElemType &elem)
{
    if (index < 0 || index >= list.length || list.capacity == 0) return false;

    elem = list.data[index];

    return true;
}

int dynamic_seq_list::find(const DSeqList &list, const ElemType elem)
{
    if (list.capacity == 0) return -1;
    
    for (int i = 0; i < list.length; i++)
    {
        if (list.data[i] == elem) return i;
    }

    return -1;
}

void dynamic_seq_list::destroy(DSeqList &list)
{
    list.length = -1;
    list.capacity = 0;
    delete[] list.data;
}

void dynamic_seq_list::print(const DSeqList &list)
{
    std::cout << "dynamic_seq_list(" << list.length << "): ";
    for (int i = 0; i < list.length; i++)
    {
        std::cout << list.data[i] << " ";
    }
    std::cout << std::endl;
}
