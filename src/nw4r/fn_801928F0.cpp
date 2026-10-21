#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    s32 unk8;
    u8 pad[0x1c - 0x0c];
    u8 unk1C;
};

extern "C" void fn_801928F0(Obj **arg0, u8 **arg1, u8 *arg2) {
    if (arg1 != 0) {
        Obj *p = *arg0;
        s32 off = p->unk8;
        u8 *r;
        if (off != 0) {
            r = (u8 *)p + off;
        } else {
            r = 0;
        }
        *arg1 = r;
    }
    if (arg2 != 0) {
        *arg2 = (*arg0)->unk1C;
    }
}
