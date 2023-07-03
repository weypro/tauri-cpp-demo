#include <gtest/gtest.h>
#include <iostream>
#include <fstream>

#include "cppdemolib_api.h"


TEST(versionTest, Major) {
    EXPECT_EQ(demolib_get_version().major, 1);
}


TEST(addTest, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(addTest, NegativeNumbers) {
    EXPECT_EQ(add(-2, -3), -5);
}

TEST(addTest, Mix) {
    EXPECT_EQ(add(2, -3), -1);
    EXPECT_EQ(add(-2, 3), 1);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}