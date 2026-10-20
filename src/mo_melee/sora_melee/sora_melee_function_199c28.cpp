#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
};

extern "C" void fn_27_199C28(Obj* p, u32 v) {
    p->b = v;
}
