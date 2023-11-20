cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(CGEnv)

add_subdirectory(CG)
add_subdirectory(CGTest)
add_subdirectory(CGApp)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET examples PROPERTY CXX_STANDARD 20)
  set_property(TARGET tests PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.