#include <types.h>
#pragma force_active on
extern const u8 lbl_8040DE50[];

typedef struct {
    u8 *unk0;
    u8 *unk4;
    s32 unk8;
    u8 unkC;
    char padD[3];
    u32 unk10;
    s32 unk14;
} Obj;

static inline void put(Obj *obj, u8 val) {
    *obj->unk4++ = val;
    if ((u32)(obj->unk4 - obj->unk0) >= obj->unk10) {
        obj->unkC = 1;
        obj->unk14 += obj->unk4 - obj->unk0;
        obj->unk4 = obj->unk0;
    }
}

void fn_802696FC(Obj *obj, u8 val, s32 nbits) {
    s32 cur;
    s32 avail;
    const u8 *masks = lbl_8040DE50;
    cur = *obj->unk4;
    avail = obj->unk8;
    while (nbits > avail) {
        int shifted = val >> (nbits - avail);
        cur |= shifted & masks[avail];
        put(obj, cur);
        if (cur == 0xff) put(obj, 0);
        nbits -= avail;
        avail = 8;
        cur = 0;
    }
    if (nbits == avail) {
        cur |= val & lbl_8040DE50[nbits];
        obj->unk8 = 8;
        put(obj, cur);
        if (cur == 0xff) put(obj, 0);
        *obj->unk4 = 0;
    } else {
        avail -= nbits;
        cur |= (val & lbl_8040DE50[nbits]) << avail;
        *obj->unk4 = cur;
        obj->unk8 = avail;
    }
}