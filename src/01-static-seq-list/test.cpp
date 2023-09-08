#include "static_seq_list.h"
#include <iostream>

int main()
{
    SSeqList list;
    static_seq_list::init(list);
    static_seq_list::print(list);

    static_seq_list::insert(list, 0, 1);
    static_seq_list::insert(list, 0, 2);
    static_seq_list::insert(list, 0, 3);
    static_seq_list::insert(list, 0, 4);
    static_seq_list::insert(list, 0, 5);
    static_seq_list::insert(list, 5, 0);
    static_seq_list::print(list);

    static_seq_list::remove_at(list, 5);
    static_seq_list::print(list);
    static_seq_list::remove_at(list, 0);
    static_seq_list::print(list);

    ElemType elem;
    static_seq_list::at(list, 3, elem);

    std::cout << elem << std::endl;
    std::cout << static_seq_list::find(list, 2) << " " << static_seq_list::find(list, 999) << std::endl;

    return 0;
}