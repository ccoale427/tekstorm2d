#include <iostream>
#include "IO/MemoryStream.h"
#include <cstring>

using namespace Tekstorm;

int main()
{
    char *buff = new char[1024];
    IO::MemoryStream mem(buff, 1024, true, true, true);
    for (int i = 0; i < 1024; i++) {
        mem.WriteByte(0);
    }
    mem.Close();
    delete[] buff;

    return 0;

}
