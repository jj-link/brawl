#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Fld {
    u32 pad0;
    u32 pad1;
    u32 pad2 : 8;
    s32 f : 4;
    u32 rest : 20;
};

extern "C" {
s32 fn_27_3957DC(Fld* p) {
    return p->f;
}
}
