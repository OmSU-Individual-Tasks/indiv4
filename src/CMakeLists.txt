add_executable(indiv4_test_prog main.cpp)
  
add_subdirectory(indiv_func)
add_subdirectory(seq_class)
add_subdirectory(menu_class)
add_subdirectory(supp_func)

target_link_libraries(indiv4_test_prog
  PRIVATE
    indiv_func
    seq_class
    menu_class
    supp_func
  )