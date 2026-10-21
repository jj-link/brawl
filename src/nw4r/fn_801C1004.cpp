#pragma force_active on
typedef int s32;

struct Obj {
    char pad[0x18];
    s32 unk18;
    s32 unk1C;
};

extern "C" void fn_801C1004(Obj *arg0, s32 arg1, s32 arg2) {
    switch (arg2) {
    case 0:
        arg0->unk1C = arg1;
        return;
    case 1:
        arg0->unk1C = arg0->unk1C + arg1;
        return;
    case 2:
        arg0->unk1C = arg0->unk18 - arg1;
        return;
    }
}
