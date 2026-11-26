#include <types.h>
#pragma force_active on

extern "C" void* fn_801D3698(u8, u32, void*);

struct Tbl {
    u8 type;
    u8 pad[3];
    u32 value;
};

struct Hdr {
    u8 pad[8];
    u8 type;
    u8 pad2[3];
    u32 value;
};

struct Rec {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u16 h4;
    u16 h6;
    u32 w[11];
};

struct Dst {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 pad3;
    u32 w4;
    u16 h8;
    u16 pad_a;
    u32 w[11];
};

struct Arg0 {
    s32 a;
    Hdr* p4;
    u32 c;
};

extern "C" s32 fn_801CCC08(Arg0 arg0, Dst* arg1) {
    Tbl* t = (Tbl*)((char*)arg0.p4 + 8);
    Rec* r = (Rec*)fn_801D3698(arg0.p4->type, t->value, t);
    Dst* out = arg1;
    out->b0 = r->b0;
    out->b1 = r->b1;
    out->b2 = r->b2;
    out->w4 = ((u32)r->b3 << 16) + r->h4;
    out->h8 = r->h6;
    out->w[0] = r->w[0];
    out->w[1] = r->w[1];
    out->w[2] = r->w[2];
    out->w[3] = r->w[3];
    out->w[4] = r->w[4];
    out->w[5] = r->w[5];
    out->w[6] = r->w[6];
    out->w[7] = r->w[7];
    out->w[8] = r->w[8];
    out->w[9] = r->w[9];
    out->w[10] = r->w[10];
    return 1;
}
