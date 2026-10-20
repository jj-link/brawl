#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct fn_27_25D310_obj {
    u8 pad[0x10];
    s32 unk10;
    u8 unk14;
};

extern "C" void fn_27_25D310(fn_27_25D310_obj *p, s32 v)
{
    if (p->unk10 == v) {
        p->unk10 = p->unk10 + 1;
    } else {
        p->unk14 = 1;
    }
}
