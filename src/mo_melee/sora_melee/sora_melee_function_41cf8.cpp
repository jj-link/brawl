#include <types.h>
#pragma force_active on
struct VObj { virtual void f0(); virtual void* f1(s32 idx); };
struct Hdr { u8* base; s32 count; };
struct Ent { f32 f[7]; u8 byte1C; u8 pad[3]; u32 w20; u32 w24; };
union Packed {
    u32 raw;
    struct {
        u32 hi:9;
        u32 gap0:2;
        u32 mid:2;
        u32 gap1:2;
        u32 low:1;
        u32 tail:16;
    } bits;
};
struct Rec { f32 f[7]; Packed h; };
struct Self { u32 unk0; s16 unk4; s16 unk6; };
extern "C" void fn_27_36074(s32, s32, s32, s32, u32, void*);
extern "C" void fn_27_41678(void*, void*);
extern "C" s32 fn_27_41CF8(Self* self, s32 a1, VObj* obj, Hdr* hdr, s32 a4, s32 a5) {
    Rec rec;
    s32 off;
    s32 i;
    i = 0;
    off = 0;
    for (; i < hdr->count; off += 0x28, i++) {
        Ent* e = (Ent*)(hdr->base + off);
        rec.f[0] = e->f[0];
        rec.f[1] = e->f[1];
        rec.f[2] = e->f[2];
        rec.f[3] = e->f[3];
        rec.f[4] = e->f[4];
        rec.f[5] = e->f[5];
        rec.f[6] = e->f[6];
        rec.h.bits.hi = e->w24;
        rec.h.bits.gap0 = 0;
        rec.h.bits.mid = e->w20;
        rec.h.bits.gap1 = 0;
        s32 b = (s32)((e->byte1C << 24) & 0xC0000000) >> 31;
        rec.h.bits.low = (u32)(-b | b) >> 31;
        fn_27_36074(a1, i, rec.h.raw >> 16 & 1, a4, rec.h.raw, e);
        void* p = obj->f1(a5 + i);
        fn_27_41678(p, &rec);
    }
    self->unk4 = a5;
    self->unk6 = i;
    self->unk0 = a4;
    return i;
}