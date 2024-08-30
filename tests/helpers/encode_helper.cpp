#include <random>
#include <chrono>
#include <sstream>

#include "../../src/helpers/encode_helper.cpp"

TEST(Encoding, toBase62)
{
    EXPECT_EQ("a", toBase62(0, 1));
    EXPECT_EQ("b", toBase62(1, 1));
    EXPECT_EQ("z", toBase62(25, 1));
    EXPECT_EQ("A", toBase62(26, 1));
    EXPECT_EQ("Z", toBase62(51, 1));
    EXPECT_EQ("aaaZ", toBase62(51, 4));
    EXPECT_EQ("aaaacLs", toBase62(10000, 7));
}