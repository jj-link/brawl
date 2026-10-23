#pragma force_active on

typedef int s32;

struct Obj {
    char pad[0x18];
    s32 unk18;
    char pad2[0x54];
    s32 unk70;
    s32 unk74;
};

extern "C" void fn_8015D294(Obj*, s32, s32);

extern "C" void fn_801BEFF4(Obj* obj, s32 arg1, s32 mode) {
    switch (mode) {
    case 0:
        arg1 += obj->unk70;
        break;
    case 1:
        arg1 += obj->unk18;
        break;
    case 2:
        arg1 = obj->unk70 + obj->unk74 - arg1;
        break;
    default:
        return;
    }

    s32 base = obj->unk70;
    if (arg1 < base) {
        arg1 = base;
    } else {
        s32 top = base + obj->unk74;
        if (arg1 > top) {
            arg1 = top;
        }
    }

    fn_8015D294(obj, arg1, 0);
}
