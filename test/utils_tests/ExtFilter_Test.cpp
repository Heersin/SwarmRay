//
// Created by heersin on 1/29/21.
//

#include "gtest/gtest.h"
#include "utils/ExtFilter.h"

TEST(ExtFilterBuildCase, TestAboutExtFilterMap)
{
    ExtFilter extFilter("nonsense");
    EXPECT_TRUE(true);
}

TEST(ExtFilterInMapCase, CheckElementInsideMap)
{
    ExtFilter extFilter("nonsense");
    string string1(".php");
    string string2(".cpp");
    string string3(".lua");

    EXPECT_TRUE(extFilter.is_in_accept(string1));
    EXPECT_TRUE(extFilter.is_in_accept(string2));
    EXPECT_FALSE(extFilter.is_in_accept(string3));
}

TEST(ExtFilterGetClassCase, CheckElementInsideMap)
{
    ExtFilter extFilter("nonsense");
    string string1(".php5");
    string string1_(".php");

    string string2(".c");
    string string2_(".cpp");

    string string3(".java");
    string string3_(".java");

    string string4(".lua");

    EXPECT_EQ(extFilter.get_class(string1), string1_);
    EXPECT_EQ(extFilter.get_class(string2), string2_);
    EXPECT_EQ(extFilter.get_class(string3), string3_);
    //EXPECT_ANY_THROW(extFilter.get_class(string4));
}