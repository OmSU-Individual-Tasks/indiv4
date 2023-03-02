add_library(menu_class "")

target_sources(menu_class
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/menu_class.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/menu_class.hpp
  )
target_include_directories(menu_class
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )