#include <types.h>
#pragma force_active on

extern "C" s32 fn_80210708(void*, void*);
extern "C" char* strncpy(char*, const char*, u32);

extern "C" s32 fn_8018BF70(void* self, void* arg1, const char* name) {
    u8* s = (u8*)self;
    if (fn_80210708(arg1, s + 4) == 0) {
        return 0;
    }
    *(void**)(s + 0x20) = arg1;
    strncpy((char*)(s + 0x30), name, 0x7f);
    s[0xaf] = 0;
    return 1;
}
