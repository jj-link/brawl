#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

struct Inner {
    char pad0[0x1c];
    u32 flags;
    char pad20[0x14];
    u32 mask;
    char pad38[4];
    u16 values[24];
};
struct Outer {
    Inner* inner;
    u32 flags;
};

extern "C" void fn_801BAAC0(Outer* obj, const u16* input, int immediate) {
    BOOL enabled = OSDisableInterrupts();
    u16 value;
    Inner* inner = obj->inner;
    if (!inner) {
        OSRestoreInterrupts(enabled);
        return;
    }
    u32 mask = 0;
    const u16* src = input;
    u16* dest = inner->values;
    value = *src++; *dest++ = value; if (value) mask |= 1;
    value = *src++; *dest++ = value; if (value) mask |= 5;
    value = *src++; *dest++ = value; if (value) mask |= 2;
    value = *src++; *dest++ = value; if (value) mask |= 6;
    value = *src++; *dest++ = value; if (value) mask |= 0x10000;
    value = *src++; *dest++ = value; if (value) mask |= 0x50000;
    value = *src++; *dest++ = value; if (value) mask |= 0x20000;
    value = *src++; *dest++ = value; if (value) mask |= 0x60000;
    value = *src++; *dest++ = value; if (value) mask |= 0x200000;
    value = *src++; *dest++ = value; if (value) mask |= 0xA00000;
    value = *src++; *dest++ = value; if (value) mask |= 0x400000;
    value = *src++; *dest++ = value; if (value) mask |= 0xC00000;
    value = *src++; *dest++ = value; if (value) mask |= 0x4000000;
    value = *src++; *dest++ = value; if (value) mask |= 0x14000000;
    value = *src++; *dest++ = value; if (value) mask |= 0x8000000;
    value = *src++; *dest++ = value; if (value) mask |= 0x18000000;
    value = *src++; *dest++ = value; if (value) mask |= 8;
    value = *src++; *dest++ = value; if (value) mask |= 0x18;
    value = *src++; *dest++ = value; if (value) mask |= 0x80000;
    value = *src++; *dest++ = value; if (value) mask |= 0x180000;
    value = *src++; *dest++ = value; if (value) mask |= 0x1000000;
    value = *src++; *dest++ = value; if (value) mask |= 0x3000000;
    value = *src++; *dest++ = value; if (value) mask |= 0x20000000;
    value = *src++; *dest++ = value; if (value) mask |= 0x60000000;
    obj->inner->mask = mask;
    if (immediate) {
        obj->inner->flags |= 0x12;
    } else {
        obj->flags |= 0x12;
    }
    OSRestoreInterrupts(enabled);
}
