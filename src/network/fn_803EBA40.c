#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 unk0;
    u32 unk4;
    s32 unk8;
} FnObj;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    char unk10[4];
} Obj;

s32 fn_803EC2F8(FnObj *arg0);

void fn_803EBA40(Obj *arg0) {
    FnObj p;

    if (arg0->unk0 == 0) {
        p.unk0 = 1;
        p.unk4 = 1;
        p.unk8 = (s32)arg0->unk10;
        arg0->unk8 = fn_803EC2F8(&p);
        arg0->unk4 = 0;
        arg0->unkC = 0;
        arg0->unk0 = 1;
    }
}
