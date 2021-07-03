##
## {{ PROJECT_NAME }}, {{ YEAR }}
## Benoît Lormeau <blormeau@outlook.com>
## Main CMakeLists
##

cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

if (${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.13")
	cmake_policy(SET CMP0076 NEW)
endif()

project(
	"{{ PROJECT_NAME }}"
	VERSION 0.1.0
	LANGUAGES CXX
)

add_executable(${PROJECT_NAME})
add_subdirectory(extern)

target_compile_features(${PROJECT_NAME}
PUBLIC
	cxx_std_20
)

target_compile_options(${PROJECT_NAME}
PUBLIC
	-W -Wall -Wextra
PRIVATE
	-fPIC
	-g3
)

target_include_directories(${PROJECT_NAME}
PUBLIC
	sources
PRIVATE
	extern
)

target_sources(${PROJECT_NAME}
PUBLIC
	sources/Common/Assertions.hpp
	sources/Common/GenericLexer.hpp
	sources/Common/Log.hpp
	sources/Common/OptionParser.hpp
	sources/Common/TTYEscapeSequences.hpp

PRIVATE
	sources/main.cpp
	sources/Common/GenericLexer.cpp
	sources/Common/Log.cpp
	sources/Common/OptionParser.cpp
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
	fmt-header-only
	# ...
)

# Tests
add_subdirectory(tests)
