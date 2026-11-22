#pragma force_active on
#include <types.h>
#include <gf/gf_application.h>

struct StartFlags {
    bool a : 1;
    bool b : 1;
};

struct Flags {
    unsigned char a : 2;
    unsigned char b : 2;
    unsigned char c : 4;
};

struct Flags2 {
    unsigned char a : 2;
    unsigned char b : 2;
    unsigned char c : 1;
    unsigned char d : 1;
    unsigned char e : 2;
};

struct Flags3 {
    unsigned char a : 1;
    unsigned char b : 7;
};

extern gfKeepFrameBuffer* lbl_805A0008;

extern "C" void fn_800381E8(void*);
extern "C" void fn_80023A50(void*);

extern "C" gfApplication* __ct__13gfApplicationFv(gfApplication* self) {
    fn_800381E8(self);
    fn_80023A50((char*)self + 0x58);

    u8* p = (u8*)self;

    ((StartFlags*)(p + 0xD0))->a = false;
    ((StartFlags*)(p + 0xD0))->b = false;
    lbl_805A0008 = (gfKeepFrameBuffer*)(p + 0xD0);
    *(int*)(p + 0xEC) &= 0x3FFFFF;
    *(int*)(p + 0xD4) = 0;
    *(int*)(p + 0xD8) = 0;
    *(int*)(p + 0xDC) = 0;
    *(int*)(p + 0xE0) = 0;
    ((Flags2*)(p + 0xED))->b = 0;
    ((Flags2*)(p + 0xED))->c = 1;
    ((Flags2*)(p + 0xED))->d = 1;
    ((Flags*)(p + 0xEE))->a = 0;
    ((Flags*)(p + 0xEE))->c = 0;
    ((Flags3*)(p + 0xEF))->a = 0;
    p[0xF0] = 0;
    p[0xF1] = 0;
    p[0xF2] = 0;
    p[0xF3] = 0;
    p[0xF4] = 1;
    p[0xF5] = 0;
    p[0xF6] = 0;
    p[0xF7] = 0;
    *(u16*)(p + 0xF8) = 0x3C;
    *(int*)(p + 0xFC) = 0x3C;
    *(int*)(p + 0x100) = 0;
    *(int*)(p + 0x104) = 0;
    *(int*)(p + 0x10C) = 0;
    *(int*)(p + 0x114) = 0;
    *(int*)(p + 0x118) = 0;
    *(int*)(p + 0x11C) = 0;
    g_gfApplication = self;
    return self;
}
