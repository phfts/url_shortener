#include <random>
#include <chrono>
#include <sstream>
#include <chrono>

#include "../../src/helpers/hash_helper.cpp"

using namespace std;

TEST(Hash, generateBase62Hash)
{
    string hash = generateBase62Hash(7);
    EXPECT_EQ(7, hash.size());
}

TEST(Hash, generateBase62HashPerf1)
{
    auto t_start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1e3; i++)
    {
        string hash = generateBase62Hash(7);
        EXPECT_EQ(7, hash.size());
    }
    auto t_end = std::chrono::high_resolution_clock::now();
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();
    EXPECT_EQ(true, elapsed_time_ms < 10);
}

TEST(Hash, generateBase62HashPerf2)
{
    auto t_start = std::chrono::high_resolution_clock::now();    
    for (int i = 0; i < 1e3; i++)
    {
        string hash = generateBase62HashV2(7);
        EXPECT_EQ(7, hash.size());
    }
    auto t_end = std::chrono::high_resolution_clock::now();
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();
    EXPECT_EQ(true, elapsed_time_ms < 10);    
}