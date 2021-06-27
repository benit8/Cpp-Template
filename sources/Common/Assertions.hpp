/*
** {{ PROJECT_NAME }}, {{ YEAR }}
** Benoît Lormeau <blormeau@outlook.com>
** Common / Assertions.hpp
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include "Common/TTYEscapeSequences.hpp"
#include <cstdio>

////////////////////////////////////////////////////////////////////////////////

#define ASSERT(x) do { \
	if (!(x)) { \
		fprintf(stderr, TTY_BRIGHT_RED("Assertion failed") ": " TTY_YELLOW(#x) " (" TTY_CYAN("%s") ":" TTY_BLUE("%d") ")\n", __FILE__, __LINE__); \
		abort(); \
	} \
} while (0)

#define ASSERT_MSG(x, fmt, ...) do { \
	if (!(x)) { \
		fprintf(stderr, TTY_BRIGHT_RED("Assertion failed") ": " TTY_YELLOW(fmt) " (" TTY_CYAN("%s") ":" TTY_BLUE("%d") ")\n", ##__VA_ARGS__, __FILE__, __LINE__); \
		abort(); \
	} \
} while (0)

#define ASSERT_NOT_REACHED() ASSERT_MSG(false, "Unreachable point reached")
#define TODO() ASSERT_MSG(false, "TODO: %s",  __PRETTY_FUNCTION__)
