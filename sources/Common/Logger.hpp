/*
** Project, 2020
** Benoît Lormeau <blormeau@outlook.com>
** Common / Logger.hpp
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include "Common/TTYEscapeSequences.hpp"
#include "tinyformat.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////

class Logger
{
public:
	enum class Level
	{
		Trace,
		Debug,
		Info,
		Warn,
		Error,
	};

public:
	static Level level() { return s_level; }
	static void set_level(Level level) { s_level = level; }
	static void set_use_colors(bool use_colors) { s_use_colors = use_colors; }

	static std::ostream& log(Level level);
	static std::ostream& trace() { return log(Level::Trace); }
	static std::ostream& debug() { return log(Level::Debug); }
	static std::ostream& info()  { return log(Level::Info); }
	static std::ostream& warn()  { return log(Level::Warn); }
	static std::ostream& error() { return log(Level::Error); }

	template <typename... Args>
	static void log(Level level, const char* fmt, const Args&... args)
	{
		log(level) << tfm::format(fmt, args...) << std::endl;
	}

	template <typename... Args> static void trace(const char* fmt, const Args&... args) { return log(Level::Trace, fmt, args...); }
	template <typename... Args> static void debug(const char* fmt, const Args&... args) { return log(Level::Debug, fmt, args...); }
	template <typename... Args> static void info(const char* fmt, const Args&... args) { return log(Level::Info, fmt, args...); }
	template <typename... Args> static void warn(const char* fmt, const Args&... args) { return log(Level::Warn, fmt, args...); }
	template <typename... Args> static void error(const char* fmt, const Args&... args) { return log(Level::Error, fmt, args...); }

private:
	static const char* level_to_string(Level level);

private:
	static Level s_level;
	static bool s_use_colors;
};
