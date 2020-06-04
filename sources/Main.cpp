/*
** PROJECT, 2020
** Main entry point
*/

#include "Utils/OptionParser.hpp"

int main(int argc, char **argv)
{
	OptionParser opt;
	if (!opt.parse(argc, argv))
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}