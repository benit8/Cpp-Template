/*
** Project Tests, 2020
** Unit
*/

#include <criterion/criterion.h>

////////////////////////////////////////////////////////////////////////////////

Test(Unit, Test1)
{
	cr_expect_eq(1 + 1, 2);
}