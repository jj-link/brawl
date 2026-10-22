#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
} Obj;

typedef struct Ent {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s16 unk14;
} Ent;

extern void fn_8022FE8C(u8, s32, s32);
extern void fn_80230104(Obj *, Ent *);
extern void fn_802301F0(Obj *, Ent *);

void fn_802326A0(Obj *arg0, Ent *arg1, s16 arg2, s32 arg3) {
    if (arg0->unk0 == 0) {
        fn_8022FE8C(arg0->unk10, arg0->unkC / 10, 1);
    }
    fn_802301F0(arg0, arg1);
    arg1->unk14 = arg2;
    arg1->unkC = arg3;
    fn_80230104(arg0, arg1);
}
