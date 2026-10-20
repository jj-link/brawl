#pragma force_active on
typedef unsigned int u32;

struct Obj27 {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_1D7E68(Obj27* p) {
    p->flags |= 0x10000;
}
}
