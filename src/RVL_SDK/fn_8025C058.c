#include <types.h>
#pragma force_active on

typedef struct Element {
    u16 unk0;
    u16 unk2;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    f32 unk1C;
    u8 unk20;
    u8 unk21;
    u8 unk22;
} Element;

typedef struct Entry {
    Element* e;
    u32 pad;
} Entry;

extern void fn_801F28F0(void*, u32, u16, u16, u32, u32, u32, u8);
extern void fn_801F2B44(void*, s32, s32, f32, f32, f32, s32, s32, s32);

void fn_8025C058(void* arg0, void* arg1, u32 arg2) {
    Entry* list;
    Element* e;
    u32 idx;

    list = *(Entry**)((u8*)arg0 + 8);
    idx = arg2 % *(u32*)((u8*)arg0 + 4);
    e = list[idx].e;
    fn_801F28F0(arg1, e->unk8, e->unk2, e->unk0, e->unk4, e->unkC, e->unk10,
                e->unk21 != e->unk22);
    fn_801F2B44(arg1, list[idx].e->unk14, list[idx].e->unk18,
                (f32)list[idx].e->unk21, (f32)list[idx].e->unk22,
                list[idx].e->unk1C, 0, list[idx].e->unk20, 0);
}
