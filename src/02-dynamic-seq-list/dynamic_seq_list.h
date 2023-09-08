#pragma once

#include "../type.h"

typedef struct
{
    ElemPtr data;
    int length;
    int capacity;
} DSeqList;

namespace dynamic_seq_list
{
    #define INIT_CAPACITY 16

    void init(DSeqList &list);
    bool insert(DSeqList &list, int index, const ElemType &elem);
    bool remove_at(DSeqList &list, int index);
    bool at(const DSeqList &list, int index, ElemType &elem);
    int find(const DSeqList &list, const ElemType elem);
    void destroy(DSeqList &list);

    void print(const DSeqList &list);
}