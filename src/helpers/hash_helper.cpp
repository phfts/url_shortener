#pragma once

#include <random>
#include <chrono>
#include <math.h>

#include "./encode_helper.cpp"

using namespace std;

string generateBase62Hash(int size)
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    const long a = 0;
    const long b = pow(62, size) - 1;
    auto x = std::uniform_int_distribution<long>(a, b)(rng);
    return toBase62(x, size);
}

string generateBase62HashV2(int size)
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    const char *alphaValues = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM0123456789";
    string ss = "";
    for (int i = 0; i < size; i++)
    {
        auto x = std::uniform_int_distribution<long>(0, 61)(rng);
        ss += alphaValues[x];
    }
    return ss;
}