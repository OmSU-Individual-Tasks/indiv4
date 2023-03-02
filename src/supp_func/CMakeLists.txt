add_library(supp_func "")

target_sources(supp_func
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/supp_func.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/supp_func.hpp
  )
target_include_directories(supp_func
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )