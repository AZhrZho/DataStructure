#include <cstring>
#include <iostream>
#include "static_seq_list.h"

void static_seq_list::init(SSeqList &list)
{
    list.length = 0;
    std::memset(list.data, 0, sizeof(ElemType) * MAX_LENGTH);
}

bool static_seq_list::insert(SSeqList &list, int index, ElemType elem)
{
    // index out of range
    if (index < 0 || index > list.length) return false;
    // list is full
    if (list.length >= MAX_LENGTH) return false;

    for (int i = list.length - 1; i >= index; i--)
    {
        list.data[i + 1] = list.data[i];
    }

    list.data[index] = elem;
    list.length++;
    return true;
}

bool static_seq_list::remove_at(SSeqList &list, int index)
{
    if (index < 0 || index >= list.length) return false;

    for (int i = index; i < list.length - 1; i++)
    {
        list.data[i] = list.data[i + 1];
    }

    list.length--;

    return true;
}

bool static_seq_list::at(const SSeqList &list, int index, ElemType &elem)
{
    if (index < 0 || index >= list.length) return false;

    elem = list.data[index];
    return true;
}

int static_seq_list::find(const SSeqList &list, const ElemType elem)
{
    for (int i = 0; i < list.length; i++)
    {
        if (list.data[i] == elem) return i;
    }
    return -1;
}

void static_seq_list::print(const SSeqList &list)
{
    std::cout << "static_seq_list(" << list.length << "): ";
    for (int i = 0; i < list.length; i++)
    {
        std::cout << list.data[i] << " ";
    }
    std::cout << std::endl;
}
