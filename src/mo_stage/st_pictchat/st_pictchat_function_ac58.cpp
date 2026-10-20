#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 pad[2];
    u32 w;
};

extern "C" {
s32 fn_73_AC58(struct Obj *p)
{
    return (s32)((p->w << 4) & 0xE0000000) >> 30;
}
}
