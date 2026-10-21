#include <string.h>
#pragma force_active on

typedef unsigned short u16;

extern "C" int fn_8004B184(void* arg0, void* src) {
    char* obj = (char*)*(void**)((char*)arg0 + 0x24);
    int offset = *(u16*)(obj + 0x33E);
    int new_offset = offset + 0x388;
    *(u16*)(obj + 0x338) = new_offset;
    *(u16*)(obj + 0x33A) = 0x4958;
    char* base = (char*)*(void**)((char*)arg0 + 0x24);
    memcpy(base + (new_offset & 0xFFFF), src, 0x4958);
    return 1;
}
