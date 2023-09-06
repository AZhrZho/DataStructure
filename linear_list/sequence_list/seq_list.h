#pragma once

#include "../../type.h"

namespace static_seq_list
{
    const int MAXSIZE = 16;

    struct list;

    list &init_list();
    void destroy_list(list& list);
    bool insert(list& list, int index, ElemType elem);
    bool push_back(list& list, ElemType elem);
    bool remove_at(list& list, int index);
    bool get(const list& list, int index, ElemType& result);
    bool get_mut(const list& list, int index, ElemType_P& pResult);
    int  length(const list& list);
    int  find(const list& list, const ElemType& elem);

    void print_list(const list& list);
}

namespace dynamic_seq_list
{
    const int INITSIZE = 16;

    struct list;

    list &init_list();
    void destroy_list(list& list);
    bool insert(list& list, int index, ElemType elem);
    bool push_back(list& list, ElemType elem);
    bool remove_at(list& list, int index);
    bool get(const list& list, int index, ElemType& result);
    bool get_mut(const list& list, int index, ElemType_P& pResult);
    int  length(const list& list);
    int  find(const list& list, const ElemType& elem);

    void print_list(const list& list);
}

typedef static_seq_list::list &seq_list_static;
typedef dynamic_seq_list::list &seq_list_dynamic;