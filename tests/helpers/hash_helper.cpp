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