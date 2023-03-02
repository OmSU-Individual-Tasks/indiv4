add_library(seq_class "")

target_sources(seq_class
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/seq_class.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/seq_class.hpp
  )
target_include_directories(seq_class
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )