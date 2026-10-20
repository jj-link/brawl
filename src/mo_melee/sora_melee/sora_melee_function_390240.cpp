#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 a : 3;
    u32 b : 3;
    u32 c : 26;
};

extern "C" void fn_27_390240(Obj *p, u32 v) {
    p->b = v;
}
