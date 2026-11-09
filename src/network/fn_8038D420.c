#include <types.h>
#include <string.h>
#pragma force_active on

void fn_8038D420(void* a, const char* b, s32 c, const char* d) {
    strcpy((char*)a + 4, b);
    strcpy((char*)a + 0x18, d);
    *(s32*)((char*)a + 0x14) = c;
    *(s32*)a = 1;
}
