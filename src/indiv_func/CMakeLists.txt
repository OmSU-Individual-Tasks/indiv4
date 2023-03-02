add_library(indiv_func "")

target_sources(indiv_func
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/indiv_func.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/indiv_func.hpp
  )
target_include_directories(indiv_func
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )