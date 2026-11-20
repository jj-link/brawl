#include <types.h>
#include <string.h>
#pragma force_active on

typedef struct Obj {
    s32 pad0;
    s32 unk4;
    u8 pad8[0x488 - 0x8];
    void (*unk488)(void *, s32, s32, s32);
    u8 pad48C[0x494 - 0x48C];
    s32 unk494;
    u8 pad498[0x6AC - 0x498];
    u16 unk6AC;
} Obj;

extern s32 fn_8035A590(s32);
extern s32 *fn_8035A598(s32, s32);
extern void fn_8035A5C8(s32, s32 *);
extern u32 fn_80388958(s32);
extern u16 fn_80388968(s32);
extern s32 fn_803890B0(void *, s32, u16);
extern s32 fn_803891A4(void);
extern s32 fn_8038B3B0(void *, s32, u8 *, s32, s32);
static inline s32 find_obj(Obj *self, u32 id, u16 key) {
    s32 n = fn_8035A590(self->unk4);
    s32 temp;
    s32 i;
    for (i = 0; i < n; i++) {
        temp = *fn_8035A598(self->unk4, i);
        if (id == fn_80388958(temp) && key == fn_80388968(temp)) {
            return i;
        }
    }
    return -1;
}

static inline void parse(Obj *self, u8 *p, s32 len, u32 *buf10, u16 *buf8) {
    u8 flags = *p;
    memcpy(buf10, p + 1, 4);
    if (flags & 0x10) {
        if (len - 5 >= 2) {
            memcpy(buf8, p + 5, 2);
        }
    } else {
        *buf8 = self->unk6AC;
    }
}

s32 fn_8038C6CC(Obj *self, u8 *p, s32 len) {
    u8 flags;
    u32 buf10;
    u16 buf8;
    u32 id;
    u16 key;
    s32 i;
    s32 n;
    s32 obj;
    s32 temp;
    s32 spC;

    if (len < 5) {
        return 4;
    }
    if (len >= 5) {
        parse(self, p, len, &buf10, &buf8);
    }
    i = find_obj(self, buf10, buf8);
    if (i == -1) {
        obj = fn_803890B0(self, buf10, buf8);
        if (fn_803891A4() != 0) {
            return 5;
        }
    } else {
        obj = *fn_8035A598(self->unk4, i);
    }
    if (fn_8038B3B0(self, obj, p, len, 0) < 0) {
        return 4;
    }
    if (i == -1) {
        spC = obj;
        fn_8035A5C8(self->unk4, &spC);
        self->unk488(self, 0, spC, self->unk494);
    }
    self->unk488(self, 1, obj, self->unk494);
    return 0;
}
