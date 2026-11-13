#include <types.h>

#pragma force_active on

extern "C" u32 fn_801931AC(const u32* table, float value);
extern float lbl_805A3220;

extern "C" void fn_80195F08(u8* const* arg0, u32* arg1, float farg) {
    u8* ptr;
    u8* p = *arg0;
    u32 offset = *(u32*)(p + 4);
    u32 flags = *(u32*)(p + 0x14);
    u32 sign = flags >> 31;

    if (offset != 0) {
        ptr = p + offset;
    } else {
        ptr = 0;
    }

    float clamped;
    if (farg <= lbl_805A3220) {
        clamped = lbl_805A3220;
    } else {
        u32 max_val = *(u16*)(ptr + 0x30);
        if ((float)max_val <= farg) {
            clamped = (float)max_val;
        } else {
            clamped = farg;
        }
    }

    arg1[0] = flags & 3;

    u32 result;
    if (sign != 0) {
        result = *(u32*)(p + 0x18);
    } else {
        const u32* table = (const u32*)(p + *(u32*)(p + 0x18) + 0x18);
        result = fn_801931AC(table, clamped);
    }

    arg1[1] = result;
}
