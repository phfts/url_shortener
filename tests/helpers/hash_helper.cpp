#include <random>
#include <chrono>
#include <sstream>

#include "../../src/helpers/hash_helper.cpp"

using namespace std;

TEST(Hash, generateBase62Hash)
{
    string hash = generateBase62Hash(7);
    EXPECT_EQ(7, hash.size());
}

TEST(Hash, generateBase62HashPerf1)
{
    for (int i = 0; i < 1e4; i++)
    {
        string hash = generateBase62Hash(7);
        EXPECT_EQ(7, hash.size());
    }
}

TEST(Hash, generateBase62HashPerf2)
{
    for (int i = 0; i < 1e4; i++)
    {
        string hash = generateBase62HashV2(7);
        EXPECT_EQ(7, hash.size());
    }
}