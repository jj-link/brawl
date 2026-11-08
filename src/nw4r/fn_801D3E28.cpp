#include <types.h>
#pragma force_active on
extern "C" void* fn_801D3698(u8, u32, void*);
extern f32 lbl_805A36C0;
struct Self { void* hdr; char* base; };
struct Output { u32 word; u8 b4, b5, b6, b7, b8, b9, b10, b11; f32 f; };
extern "C" s32 fn_801D3E28(Self* __restrict self, Output* out, s32 idx, s32 idx2) {
    char* base = self->base;
    char* entry = base + idx * 8;
    char* p = (char*)fn_801D3698(*(u8*)(entry + 0xc), *(u32*)(entry + 0x10), base + 8);
    p = (char*)fn_801D3698(*(u8*)(p + 0x10), *(u32*)(p + 0x14), self->base + 8);
    p += idx2 * 8;
    p = (char*)fn_801D3698(*(u8*)(p + 4), *(u32*)(p + 8), self->base + 8);
    out->word = *(u32*)p;
    out->b4 = p[4];
    out->b5 = p[5];
    out->b6 = p[6];
    out->b7 = p[7];
    out->b8 = p[12];
    out->b11 = p[13];
    if (*(u16*)((char*)self->hdr + 6) >= 0x101) {
        out->b9 = p[14];
        out->b10 = p[15];
        out->f = *(f32*)(p + 16);
    } else {
        f32 value = lbl_805A36C0;
        out->b9 = 0x40;
        out->b10 = 0;
        out->f = value;
    }
    return 1;
}