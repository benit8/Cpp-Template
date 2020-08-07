/*
** Project, 2020
** Benoît Lormeau <blormeau@outlook.com>
** Main entry point
*/

#include "Common/OptionParser.hpp"

int main(int argc, char** argv)
{
	OptionParser opt;
	if (!opt.parse(argc, argv))
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}