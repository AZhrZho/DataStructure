#include "linear_list.h"
#include <iostream>

int main()
{
	test_static_seq_list();
	test_dynamic_seq_list();
	return 0;
}

void test_static_seq_list()
{
	std::cout << "init list" << std::endl;
	seq_list_static list = static_seq_list::init_list();
	static_seq_list::push_back(list, 0);
	static_seq_list::push_back(list, 1);
	static_seq_list::push_back(list, 2);
	static_seq_list::push_back(list, 3);
	static_seq_list::push_back(list, 4);
	static_seq_list::push_back(list, 5);
	static_seq_list::print_list(list);

	std::cout << std::endl << "remove" << std::endl;
	static_seq_list::remove_at(list, 0);
	static_seq_list::remove_at(list, static_seq_list::length(list) - 1);
	static_seq_list::print_list(list);

	std::cout << std::endl << "insert" << std::endl;
	static_seq_list::insert(list, 0, 1);
	static_seq_list::insert(list, 2, 4);
	static_seq_list::print_list(list);

	std::cout << std::endl << "get" << std::endl;
	ElemType elem;
	static_seq_list::get(list, 0, elem);
	std::cout << elem << std::endl;
	elem = 999;
	static_seq_list::print_list(list);

	std::cout << std::endl << "alter" << std::endl;
	ElemType_P elem_p;
	static_seq_list::get_mut(list, 0, elem_p);
	std::cout << *elem_p << std::endl;
	*elem_p = 999;
	static_seq_list::print_list(list);

	std::cout << std::endl << "find" << std::endl;
	int index = static_seq_list::find(list, 4);
	std::cout << index << std::endl;
	index = static_seq_list::find(list, 0);
	std::cout << index << std::endl;

	std::cout << std::endl << "invalid" << std::endl;
	static_seq_list::remove_at(list, 7);
	static_seq_list::insert(list, 8, 10);
	static_seq_list::insert(list, 100, 100);
	static_seq_list::print_list(list);

	std::cout << std::endl << "destroy" << std::endl;
	static_seq_list::destroy_list(list);

	// should be invalid
	static_seq_list::print_list(list);
}

void test_dynamic_seq_list()
{
	std::cout << "init list" << std::endl;
	seq_list_dynamic list = dynamic_seq_list::init_list();
	dynamic_seq_list::push_back(list, 0);
	dynamic_seq_list::push_back(list, 1);
	dynamic_seq_list::push_back(list, 2);
	dynamic_seq_list::push_back(list, 3);
	dynamic_seq_list::push_back(list, 4);
	dynamic_seq_list::push_back(list, 5);
	dynamic_seq_list::print_list(list);

	std::cout << std::endl << "remove" << std::endl;
	dynamic_seq_list::remove_at(list, 0);
	dynamic_seq_list::remove_at(list, dynamic_seq_list::length(list) - 1);
	dynamic_seq_list::print_list(list);

	std::cout << std::endl << "insert" << std::endl;
	dynamic_seq_list::insert(list, 0, 1);
	dynamic_seq_list::insert(list, 2, 4);
	dynamic_seq_list::print_list(list);

	std::cout << std::endl << "get" << std::endl;
	ElemType elem;
	dynamic_seq_list::get(list, 0, elem);
	std::cout << elem << std::endl;
	elem = 999;
	dynamic_seq_list::print_list(list);

	std::cout << std::endl << "alter" << std::endl;
	ElemType_P elem_p;
	dynamic_seq_list::get_mut(list, 0, elem_p);
	std::cout << *elem_p << std::endl;
	*elem_p = 999;
	dynamic_seq_list::print_list(list);

	std::cout << std::endl << "find" << std::endl;
	int index = dynamic_seq_list::find(list, 4);
	std::cout << index << std::endl;
	index = dynamic_seq_list::find(list, 0);
	std::cout << index << std::endl;

	std::cout << std::endl << "invalid" << std::endl;
	dynamic_seq_list::remove_at(list, 7);
	dynamic_seq_list::insert(list, 8, 10);
	dynamic_seq_list::insert(list, 100, 100);
	dynamic_seq_list::print_list(list);

	std::cout << std::endl << "destroy" << std::endl;
	dynamic_seq_list::destroy_list(list);

	// should be invalid
	dynamic_seq_list::print_list(list);
}
