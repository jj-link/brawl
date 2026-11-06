#include <types.h>
#include <new>
#pragma force_active on

extern int lbl_80466718[];

struct Stream {
    void* vtable;
    u8 available;
    u8 padding[7];
    s32 fieldC;
    s32 field10;
    s32 base;
    s32 length;
    s32 position;

    Stream(s32 address, s32 size) {
        available = 0;
        fieldC = 0;
        field10 = 0;
        vtable = lbl_80466718;
        base = address;
        length = size;
        position = 0;
    }
};

extern "C" void* fn_801C0F28(void* object, void* buffer, u32 size, s32 offset, s32 length) {
    s32 base = *reinterpret_cast<s32*>(static_cast<u8*>(object) + 0x108);
    if (base == 0) {
        return 0;
    }
    if (size < 0x20U) {
        return 0;
    }
    return new (buffer) Stream(offset + base, length);
}
