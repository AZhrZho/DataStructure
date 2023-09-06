add_executable (linear_list "linear_list.cpp" "linear_list.h" "sequence_list/seq_list.h"  "sequence_list/seq_list.cpp" "linked_list/singly_linked_list.h" "linked_list/singly_linked_list.cpp" "linked_list/doubly_linked_list.h" "linked_list/doubly_linked_list.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET linear_list PROPERTY CXX_STANDARD 20)
endif()

project("linear_list")