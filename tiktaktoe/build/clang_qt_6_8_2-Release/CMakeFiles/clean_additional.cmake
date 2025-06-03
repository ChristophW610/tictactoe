# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/tiktaktoe_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/tiktaktoe_autogen.dir/ParseCache.txt"
  "tiktaktoe_autogen"
  )
endif()
