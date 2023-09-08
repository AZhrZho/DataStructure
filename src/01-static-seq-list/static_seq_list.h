#pragma once
#include "../type.h"

// 静态顺序表

#define MAX_LENGTH 16

typedef struct
{
    ElemType data[MAX_LENGTH];
    int length;
} SSeqList;

namespace static_seq_list
{
    void init(SSeqList &list);
    bool insert(SSeqList &list, int index, ElemType elem);
    bool remove_at(SSeqList &list, int index);
    bool at(const SSeqList &list, int index, ElemType &elem);
    int find(const SSeqList &list, const ElemType elem);

    void print(const SSeqList &list);
}