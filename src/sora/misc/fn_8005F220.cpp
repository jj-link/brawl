#include <types.h>
#pragma force_active on

extern "C" bool fn_8005F220(void* self, s32 arg1) {
    u32 count = *(u32*)((char*)self + 0x5C);
    u32 i;
    u32 low = (u32)arg1 & 0xFFFF;
    s32 off;
    void* found;

    i = 0;
    off = 0;

    for (; i < count; i++) {
        u32* base = *(u32**)((char*)self + 0x58);
        char* entry = (char*)base + off;
        if (*(s32*)entry != 0 &&
            (u32)(arg1 >> 16) == (u32)*(s32*)(entry + 0x10)) {
            found = (char*)base + i * 0x18;
            goto done;
        }
        off += 0x18;
    }

    found = NULL;

done:
    if (found != NULL) {
        u8* inner = *(u8**)((char*)found + 0xC);
        u8 val = *(u8*)(inner + (low << 4) + 0x1C);
        if (val & 2) {
            return true;
        }
    }
    return false;
}
