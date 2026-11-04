#include <types.h>
#pragma force_active on

struct Xyz {
    u16* m_ptr;
    s8* m_table;
};

struct Ent {
    char pad0[0x14];
    s32 off14;
    u16 idx18;
    u8 count1A;
    char pad1[0x3C - 0x1B];
};

struct Sub {
    char pad0[0x10];
    s32 v10;
    s32 v14;
    char pad1[0x4];
    u32 flags1C;
};

extern "C" void* fn_80197054(void* arg0, u32 arg1);
extern "C" Sub* fn_80196C24(void* self, s32 index);
extern "C" Sub* fn_80196A70(void* self, s32 index);
extern "C" s32 fn_801B6A10(Xyz* self, u32 idx, s32 val);
extern "C" void fn_801B6A80(Xyz* self, s32 val);

extern "C" s32 fn_8019CE24(char* arg0, Xyz* arg1, u32 arg2) {
    Ent* ent;
    Sub* sub;
    u16* p;
    u32 k;
    u32 i;
    u32 j;

    ent = (Ent*)fn_80197054(arg0 + 0x20, arg2);
    if (ent == 0) {
        return 0;
    }
    j = ent->count1A;
    k = 7;
    i = 0;
    if (j != 0) {
        p = (u16*)ent;
        for (; i < j; i++) {
            if (*(u16*)((char*)p + 0x3C) != 0xFFFF) {
                sub = fn_80196C24(arg0 + 0x20, *(u16*)((char*)p + 0x3C));
                fn_801B6A10(arg1, i, sub->v10);
                if (sub->flags1C & 8) {
                    fn_801B6A10(arg1, k--, sub->v14);
                }
            } else {
                fn_801B6A10(arg1, i, -1);
            }
            p++;
        }
    }
    for (; j <= k; j++) {
        fn_801B6A10(arg1, j, -1);
    }
    if (ent->off14 != 0) {
        sub = fn_80196A70(arg0 + 0x20, ent->idx18);
        fn_801B6A80(arg1, sub->v10);
    } else {
        fn_801B6A80(arg1, -1);
    }
    return 1;
}
