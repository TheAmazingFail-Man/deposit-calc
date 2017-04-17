#include "deposit.h"
#include <ctest.h>
#include <stdio.h>

//Tests for data

CTEST(check_data, test1)
{
	ASSERT_EQUAL(0, data(10000, 365));
}

CTEST(check_data, test2)
{
        ASSERT_EQUAL(-1, data(9999, 365));
}

CTEST(check_data, test3)
{
        ASSERT_EQUAL(-1, data(10000, 366));
}

CTEST(check_data, test4)
{
        ASSERT_EQUAL(-1, data(-1, 365));
}

CTEST(check_data, test5)
{
        ASSERT_EQUAL(-1, data(10000, -1));
}

CTEST(check_data, test6)
{
        ASSERT_EQUAL(-1, data(-1, -1));
}

//Tests for results

CTEST(calculating, test1)
{
        ASSERT_EQUAL(90000, result(100000, 30));
} 

CTEST(calculating, test2)
{
        ASSERT_EQUAL(102000, result(100000, 31));
}

CTEST(calculating, test3)
{
        ASSERT_EQUAL(102000, result(100000, 120));
}

CTEST(calculating, test4)
{
        ASSERT_EQUAL(106000, result(100000, 121));
}

CTEST(calculating, test5)
{
        ASSERT_EQUAL(106000, result(100000, 240));
}

CTEST(calculating, test6)
{
        ASSERT_EQUAL(112000, result(100000, 241));
}

CTEST(calculating, test7)
{
        ASSERT_EQUAL(99000, result(110000, 30));
} 

CTEST(calculating, test8)
{
        ASSERT_EQUAL(113300, result(110000, 31));
}

CTEST(calculating, test9)
{
        ASSERT_EQUAL(113300, result(110000, 120));
}

CTEST(calculating, test10)
{
        ASSERT_EQUAL(118800, result(110000, 121));
}

CTEST(calculating, test11)
{
        ASSERT_EQUAL(118800, result(110000, 240));
}
