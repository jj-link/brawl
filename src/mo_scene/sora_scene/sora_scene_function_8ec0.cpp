#include <string.h>
#pragma force_active on

extern "C" void fn_1_8EC0(void* self)
{
    unsigned int* fields = (unsigned int*)((char*)self + 0x360);
    fields[0] = 0;
    fields[1] = 0;
    fields[2] = 1;
    fields[3] = 0;
    fields[4] = 0;
    fields[5] = 0xFFFFFFFF;
    fields[6] = 0xFFFFFFFF;
    fields[7] = 0;
    *((unsigned char*)self + 0x380) = 0;
    memset((char*)self + 0x384, 0, 0x10);
}
