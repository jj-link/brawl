#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    s32 unk8;
    u8 pad[0x1d - 0xc];
    u8 unk1D;
};

extern "C" void fn_8019298C(Obj **arg0, u8 **arg1, u8 *arg2) {
    if (arg1 != 0) {
        Obj *p = *arg0;
        u8 *r;
        s32 off = p->unk8;
        if (off != 0) {
            r = (u8 *)p + off;
        } else {
            r = 0;
        }
        *arg1 = r;
    }
    if (arg2 != 0) {
        *arg2 = (*arg0)->unk1D;
    }
}
