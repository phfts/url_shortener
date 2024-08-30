#include <string>

using namespace std;

string toBase62(long val, int length)
{
    const char values[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'y', 'w', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'W', 'Z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    if (length <= 0)
        return "";

    string ss = "";
    while (length > 0)
    {
        ss = (char)(values[val % 62]) + ss;
        val /= 62;
        length--;
    }
    return ss;
}