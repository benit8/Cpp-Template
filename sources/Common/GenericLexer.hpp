/*
** {{ PROJECT_NAME }}, {{ YEAR }}
** Benoît Lormeau <blormeau@outlook.com>
** Common / GenericLexer.hpp
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <functional>
#include <optional>
#include <string_view>

////////////////////////////////////////////////////////////////////////////////

class GenericLexer
{
public:
	explicit GenericLexer(std::string_view input);
	virtual ~GenericLexer() = default;

	using Condition = std::function<bool(char)>;

	size_t tell() const { return m_index; }
	size_t tell_remaining() const { return m_input.length() - m_index; }

	bool at_end() const;

	char peek(size_t offset = 0) const;

	bool next_is(char expected) const;
	bool next_is(std::string_view expected) const;
	bool next_is(Condition) const;

	char consume();
	bool consume_specific(char specific);
	bool consume_specific(std::string_view str);
	std::string_view consume(size_t count);
	std::string_view consume_all();
	std::string_view consume_line();
	std::string_view consume_while(Condition);
	std::string_view consume_until(char stop);
	std::string_view consume_until(std::string_view stop);
	std::string_view consume_until(Condition);
	std::optional<std::string_view> consume_quoted_string();

	void ignore(size_t count = 1);
	void ignore_while(Condition);
	void ignore_until(char stop);
	void ignore_until(std::string_view stop);
	void ignore_until(Condition);

protected:
	std::string_view m_input;
	size_t m_index { 0 };
};
