#include <types.h>
#include <nw4r/g3d/g3d_resmat.h>
#pragma force_active on
struct Entry { u8 pad[0x18]; s32 flags; };
struct Sub { u8 pad0[0x10]; s32 unk10; u8 pad14[4]; s32 unk18; u16 unk1C; };
struct Arg { u8 mask0; u8 mask1; u8 pad2[2]; Entry* ent[8]; Sub* sub[8]; };
extern "C" {
void fn_801F2D60(void*, s32*, s32*, f32*, f32*, f32*, u8*, u8*, s32*);
u32 fn_801F2D3C(void*);
s32 fn_801F2D48(void*);
void fn_80192B00(Entry**, s32*, u16*, u16*, s32*, f32*, f32*, u8*);
void fn_80192A44(Entry**, s32*, u16*, u16*, s32*, f32*, f32*, u8*);
void fn_801F2AFC(void*, s32, u16, u16, s32, u32, s32, u8, s32);
void fn_801F28F0(void*, s32, u16, u16, s32, u32, s32, u8);
void fn_801F2B44(void*, s32, s32, f32, f32, f32, u8, u8, s32);
void* fn_80190DC8(s32, s32);
void fn_801F3004(void*, void*, s32, u16);
}
extern "C" void fn_80198FCC(nw4r::g3d::ResTexObj* arg0, s32 arg1, Arg* arg2) {
    u16 w; void* p; s32 v; u8* pb; s32 i; u32 m;
    Entry* sp3C; s32 sp38; s32 sp34; f32 sp30; f32 sp2C; f32 sp28; s32 sp24; s32 sp20; s32 sp1C; s32 sp18; u16 sp16; u16 sp14; u8 sp12; u8 sp11; u8 sp10; s32 j;
    m = arg2->mask0; pb = (u8*)arg2;
    for (i = 0; m != 0; i++, m >>= 1, pb += 4) {
        if (m & 1) {
            void* tex; u32 a; s32 b;
            sp3C = *(Entry**)(pb + 4);
            tex = arg0->GetTexObj((GXTexMapID)i);
            fn_801F2D60(tex, &sp38, &sp34, &sp30, &sp2C, &sp28, &sp12, &sp11, &sp24);
            a = fn_801F2D3C(tex); b = fn_801F2D48(tex);
            if (sp3C->flags & 1) {
                fn_80192B00(&sp3C, &sp20, &sp16, &sp14, &sp18, &sp30, &sp2C, &sp10);
                fn_801F2AFC(tex, sp20, sp16, sp14, sp18, a, b, sp10, i);
            } else {
                fn_80192A44(&sp3C, &sp20, &sp16, &sp14, &sp1C, &sp30, &sp2C, &sp10);
                fn_801F28F0(tex, sp20, sp16, sp14, sp1C, a, b, sp10);
            }
            fn_801F2B44(tex, sp38, sp34, sp30, sp2C, sp28, sp12, sp11, sp24);
        }
    }
    u32 m2 = arg2->mask1;
    for (j = 0; m2 != 0; j++, m2 >>= 1, arg2 = (Arg*)((u8*)arg2 + 4)) {
        if (m2 & 1) {
            Sub* s = *(Sub**)((u8*)arg2 + 0x24);
            void* r;
            if (s->unk10 != 0) p = (void*)((u8*)s + s->unk10); else p = 0;
            v = s->unk18; w = s->unk1C;
            r = fn_80190DC8(arg1, j); fn_801F3004(r, p, v, w);
        }
    }
}
