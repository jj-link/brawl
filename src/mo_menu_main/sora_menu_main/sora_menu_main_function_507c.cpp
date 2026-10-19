#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern void fn_800288A4(gfPadStatus* status);
extern void fn_800B9984(void* arg);
extern int fn_800FAD8C(void* arg);
}

extern gfPadSystem* g_gfPadSystem;

struct SubObj {
    char _0[0x10];
};

struct Self {
    char _0[0x80];
    SubObj sub;
    u32 _0x90;
    char _0x94[0x8];
    u32 _0x9c;
};

extern "C" u32 fn_2_507C(Self* self) {
    u32 result = 0;
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    fn_800288A4(&status);
    fn_800B9984(&self->sub);

    status.m_buttonsPressedThisFrame2.bits |= self->_0x90;
    u32 buttons2 = self->_0x9c;

    u32 buttons = status.m_buttonsPressedThisFrame2.bits;
    if (buttons & 0x8)
        result |= 0x8;
    if (buttons & 0x4)
        result |= 0x4;
    if (buttons & 0x1)
        result |= 0x1;
    if (buttons & 0x2)
        result |= 0x2;

    if (buttons2 & 0x1)
        result |= 0x40;
    if (buttons2 & 0x2)
        result |= 0x20;

    int ret = fn_800FAD8C(&self->sub);
    if (ret & 0x1)
        result |= 0x1000;
    if (ret & 0x2)
        result |= 0x100;
    if (ret & 0x4)
        result |= 0x200;
    if (ret & 0x8)
        result |= 0x40;
    if (ret & 0x10)
        result |= 0x20;

    return result;
}
