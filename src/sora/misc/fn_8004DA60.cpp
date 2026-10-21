#include <string.h>
#pragma force_active on

extern "C" void fn_8004DA60(void* base, int index, void* src) {
    void* ptr = *(void**)((char*)base + 0x28);
    memcpy((char*)ptr + index * 0x124 + 0xf4, src, 0x2d);
}
