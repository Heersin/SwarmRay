//
// Created by heersin on 1/29/21.
//

#include "gtest/gtest.h"
#include "utils/PathGenerator.h"
#include <iostream>

#include <boost/filesystem.hpp>

using namespace  std;

TEST(PathGeneratorUnitTest, CheckBuild)
{
    string default_path("../../test/utils_tests/code_samples");


    PathGenerator pathBuilder(default_path);
    pathBuilder.collectAllFiles();

    string string1(".lua");
    string string2(".cpp");
    string sub_dir(".php");

    EXPECT_TRUE(pathBuilder.getAllTargetFiles().count(string1) == 0);
    EXPECT_TRUE(pathBuilder.getAllTargetFiles().count(string2) == 1);
    EXPECT_TRUE(pathBuilder.getAllTargetFiles().count(sub_dir) == 2);

}