#include <types.h>
#pragma force_active on

extern "C" u32 fn_8_4AC(void* arg) {
    u8* p = *(u8**)((char*)arg + 0x1ac);
    p = *(u8**)(p + 0x1d0c);
    p = *(u8**)(p + 0x35c);
    p = *(u8**)p;
    if (p[0x1a4] != 0) {
        return *(u32*)(p + 0x48);
    }
    return 0;
}
