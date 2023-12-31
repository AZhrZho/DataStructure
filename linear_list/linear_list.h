#pragma once

#include "sequence_list/seq_list.h"
#include "linked_list/singly_linked_list.h"
#include "linked_list/doubly_linked_list.h"

#include <map>
#include <string>

void test_static_seq_list();
void test_dynamic_seq_list();
void test_singly_linked_list();
void test_doubly_linked_list();

//typedef void(*test_proc_t)();
//std::map<std::string, test_proc_t> map_menu = std::map<std::string, test_proc_t>();
//
//#define add_menu_proc(proc) map_menu.insert(std::make_pair<std::string, test_proc_t>(std::string(#proc), ##proc))