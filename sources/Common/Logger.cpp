/*
** {{ PROJECT_NAME }}, {{ YEAR }}
** Benoît Lormeau <blormeau@outlook.com>
** Common / Logger.cpp
*/

#include "Common/Assertions.hpp"
#include "Common/Logger.hpp"
#include "fmt/chrono.h"
#include "fmt/color.h"
#include "fmt/format.h"
#include <sys/time.h>

////////////////////////////////////////////////////////////////////////////////

Logger::Level Logger::s_level = Logger::Level::Trace;

////////////////////////////////////////////////////////////////////////////////

void Logger::log(Level level, fmt::string_view format, fmt::format_args args)
{
	static const struct {
		const char* name;
		fmt::text_style style;
	} levels[] = {
		{ "TRACE",     fmt::emphasis::faint },
		{ "DEBUG",     fmt::fg(fmt::terminal_color::magenta) },
		{ "INFO",      fmt::fg(fmt::terminal_color::blue) },
		{ "NOTICE",    fmt::fg(fmt::terminal_color::green) },
		{ "WARNING",   fmt::fg(fmt::terminal_color::yellow) },
		{ "ERROR",     fmt::fg(fmt::terminal_color::red) },
		{ "CRITICAL",  fmt::emphasis::bold | fmt::fg(fmt::terminal_color::red) },
		{ "ALERT",     fmt::emphasis::bold | fmt::emphasis::underline | fmt::fg(fmt::terminal_color::red) },
		{ "EMERGENCY", fmt::emphasis::bold | fmt::emphasis::underline | fmt::fg(fmt::terminal_color::red) },
	};

	if (level < s_level)
		return;

	std::time_t t = std::time(nullptr);
	fmt::print("{} {:9} {}\n",
		fmt::format(fmt::emphasis::faint, "{:%Y-%m-%d %H:%M:%S}", fmt::localtime(t)),
		fmt::format(levels[level].style, "{}", levels[level].name),
		fmt::vformat(format, args)
	);
}
