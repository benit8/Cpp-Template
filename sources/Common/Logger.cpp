/*
** {{ PROJECT_NAME }}, {{ YEAR }}
** Benoît Lormeau <blormeau@outlook.com>
** Common / Logger.cpp
*/

#include "Common/Assertions.hpp"
#include "Common/Logger.hpp"
#include <sys/time.h>

////////////////////////////////////////////////////////////////////////////////

Logger::Level Logger::s_level = Logger::Level::Trace;
bool Logger::s_use_colors = true;

////////////////////////////////////////////////////////////////////////////////

std::ostream& Logger::log(Logger::Level level)
{
	static std::ostream nullstream(nullptr);
	if (level < s_level) {
		return nullstream;
	}

	struct timeval tv;
	gettimeofday(&tv, NULL);
	int millisec = tv.tv_usec / 1000.0;

	struct tm* lt = localtime(&tv.tv_sec);
	char tbuf[16] = {0};
	int n = strftime(tbuf, sizeof(tbuf), "%H:%M:%S", lt);
	snprintf(tbuf + n, sizeof(tbuf) - n - 1, ".%03d", millisec);

	return std::cout << TTY_FAINT_ON << tbuf << TTY_FAINT_OFF << " " << level_to_string(level) << " " << std::dec;
}

const char* Logger::level_to_string(Logger::Level level)
{
	switch (level) {
		case Logger::Level::Trace: return s_use_colors ? TTY_FAINT_ON "TRACE" TTY_FAINT_OFF : "TRACE";
		case Logger::Level::Debug: return s_use_colors ? TTY_FG_MAGENTA "DEBUG" TTY_FG_DEFAULT : "DEBUG";
		case Logger::Level::Info:  return s_use_colors ? TTY_FG_GREEN "INFO " TTY_FG_DEFAULT : "INFO ";
		case Logger::Level::Warn:  return s_use_colors ? TTY_FG_YELLOW "WARN " TTY_FG_DEFAULT : "WARN ";
		case Logger::Level::Error: return s_use_colors ? TTY_FG_RED "ERROR" TTY_FG_DEFAULT : "ERROR";
	}
	ASSERT_NOT_REACHED();
}
