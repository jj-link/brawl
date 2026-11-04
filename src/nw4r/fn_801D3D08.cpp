#include <types.h>
#pragma force_active on

extern "C" void* fn_801D3698(u8, u32, void*);
extern f32 lbl_805A36C0;

struct Self {
    void* hdr;    // 0x00: header with u16 type at +6
    char* base;   // 0x04
};

struct Val {
    f32 f;     // 0x00
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
};

extern "C" s32 fn_801D3D08(const Self* self, Val* out, s32 idx) {
    char* base = self->base;
    char* entry = base + idx * 8;
    void* p1 = fn_801D3698(*(u8*)(entry + 0xc), *(u32*)(entry + 0x10), base + 8);
    void* p2 = fn_801D3698(*(u8*)p1, *(u32*)((char*)p1 + 4), self->base + 8);
    u16 type = *(u16*)((char*)self->hdr + 6);
    Val* v = (Val*)p2;
    if (type == 0x102) {
        out->f = v->f;
        out->b4 = v->b4;
        out->b5 = v->b5;
        out->b6 = v->b6;
        out->b7 = v->b7;
        out->b8 = v->b8;
        out->b9 = v->b9;
    } else if (type == 0x101) {
        out->f = v->f;
        out->b4 = v->b4;
        out->b5 = v->b5;
        out->b6 = 0;
        out->b7 = 0;
        out->b8 = 0;
        out->b9 = 0x7f;
    } else {
        out->f = lbl_805A36C0;
        out->b4 = 0x40;
        out->b5 = 0;
        out->b6 = 0;
        out->b7 = 0;
        out->b8 = 0;
        out->b9 = 0x7f;
    }
    return 1;
}
