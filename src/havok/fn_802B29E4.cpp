#include <types.h>
#pragma force_active on

extern "C" void fn_8031590C(void* ptr, u32 index);

extern "C" void fn_802B29E4(void* self, u16 key) {
    u8 count = *(u8*)((char*)self + 0x32);
    char* ptr = (char*)self;
    for (s32 i = 0; i < count; i++) {
        if (key == *(u16*)(ptr + 0x36)) {
            fn_8031590C((char*)self + 0x30, (u32)i);
            return;
        }
        ptr += 8;
    }
}
