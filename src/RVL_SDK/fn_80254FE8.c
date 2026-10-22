#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct Obj {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 pad6[0xE];
    u8 unk14;
    u8 unk15;
} Obj;

extern void *fn_8022EFF8(s32);
extern void fn_80254D68(s32, s32, void *);

void fn_80254FE8(s32 arg0, s32 arg1) {
    Obj *p = (Obj *)fn_8022EFF8(2);
    if (p) {
        p->unk4 = 0xC;
        p->unk14 = ((arg1 != 0) ? 2 : 0) | 0xA1;
        p->unk15 = 1;
        p->unk2 = 2;
        fn_80254D68(arg0, 0, p);
    }
}
