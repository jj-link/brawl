#pragma force_active on
typedef int s32;

typedef struct Fn2414Obj {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    struct Fn2414Obj* unk30;
    s32 unk34;
} Fn2414Obj;

s32 fn_803E2414(Fn2414Obj* arg0, Fn2414Obj* arg1, s32 arg2, s32 arg3) {
    arg0->unk30 = arg1;
    arg0->unk34 = arg2;
    arg0->unk08 = arg3;
    arg0->unk00 = 1;
    if (arg1 != 0) {
        arg1->unk08 = 0;
    }
    arg0->unk18 = 0;
    arg0->unk14 = 0;
    arg0->unk0C = 0;
    arg0->unk10 = 0;
    arg0->unk1C = 0;
    return 0;
}
