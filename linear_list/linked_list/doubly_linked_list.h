#pragma once

#include "../../type.h"

namespace doubly_linked_list
{
    struct list_node;
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

typedef doubly_linked_list::list& linked_list_double;