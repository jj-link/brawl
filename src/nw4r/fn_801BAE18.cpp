#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef unsigned short u16;
typedef unsigned char u8;

struct State {
    u8* buffer;
    u32 flags;
};

extern "C" void fn_801BAE18(State* arg0, u16* data)
{
    BOOL enabled = OSDisableInterrupts();
    u8* buf = arg0->buffer;

    if (buf == 0) {
        OSRestoreInterrupts(enabled);
        return;
    }

    u16 mask = 0;
    u16 value;
    u16* output = (u16*)(buf + 0x102);
    u16* input = data;

    value = *input++; *output++ = value;
    if (value != 0) mask |= 1;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 2;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 4;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 8;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 0x10;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 0x20;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 0x40;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 0x80;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 0x100;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 0x200;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 0x400;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 0x800;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 0x1000;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 0x2000;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 0x4000;
    value = *input++; *output++ = value;
    if (value != 0) mask |= 0x8000;

    *(u16*)(arg0->buffer + 0x100) = mask;
    arg0->flags |= 0x03000000;
    OSRestoreInterrupts(enabled);
}
