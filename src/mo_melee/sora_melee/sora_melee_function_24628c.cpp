#pragma force_active on
typedef unsigned char u8;

struct Fn27Obj {
    u8 pad_00[0x40];
    u8 flag_40;
    u8 pad_41[0x48 - 0x41];
    float val_48;
    float val_4c;
};

extern "C" void fn_27_24628C(Fn27Obj* p)
{
    p->val_4c = p->val_48;
    p->flag_40 = 1;
}
