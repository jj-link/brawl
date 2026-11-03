#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

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

extern void fn_8035A5C8(s32, s32 *);
extern s32 fn_803890B0(void *, s32, u16);
extern s32 fn_803891A4(void);
extern s32 fn_8038B1A0(void *, s32);
extern s32 fn_8038B278(void *, u8 *, s32);
extern s32 fn_8038B3B0(void *, s32, u8 *, s32, s32);
extern s32 fn_803F6150(const void *, const void *, u32);
extern void *memcpy(void *, const void *, u32);
extern int lbl_8059FBD0;

s32 fn_8038B680(Obj *self, u8 *p, s32 len) {
    u8 flags;
    s32 var;
    s32 sp10;
    u16 sp8;
    s32 spC;
    s32 temp;
    s32 result;

    if (len < 1) {
        return 0;
    }
    flags = *p;
    var = 5;
    if (flags & 0x02) {
        var = 9;
    }
    if (flags & 0x08) {
        var += 4;
    }
    if (flags & 0x10) {
        var += 2;
    }
    if (flags & 0x20) {
        var += 2;
    }
    if (len < var) {
        return 0;
    }
    if ((flags & 0x40) && fn_8038B278(self, p + var, len - var) == 0) {
        return 0;
    }
    if ((flags & 0x80) && fn_8038B1A0(p + var, len - var) == 0) {
        return 0;
    }
    if (fn_803F6150(p + 1, &lbl_8059FBD0, 4) == 0) {
        return -1;
    }
    if (len >= 5) {
        flags = *p;
        memcpy(&sp10, p + 1, 4);
        if (flags & 0x10) {
            if (len - 5 >= 2) {
                memcpy(&sp8, p + 5, 2);
            }
        } else {
            sp8 = self->unk6AC;
        }
    }
    temp = fn_803890B0(self, sp10, sp8);
    if (fn_803891A4() != 0) {
        return -2;
    }
    result = fn_8038B3B0(self, temp, p, len, 1);
    spC = temp;
    fn_8035A5C8(self->unk4, &spC);
    self->unk488(self, 0, spC, self->unk494);
    return result;
}
