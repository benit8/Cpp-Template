/*
** {{ PROJECT_NAME }}, {{ YEAR }}
** Benoît Lormeau <blormeau@outlook.com>
** Main entry point
*/

#include "Common/Logger.hpp"
#include "Common/OptionParser.hpp"

int main(int argc, char** argv)
{
	Logger::trace("Program started!");

	OptionParser opt;
	if (!opt.parse(argc, argv))
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}
