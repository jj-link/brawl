#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 a : 4;
    u32 b : 2;
    u32 c : 26;
};

extern "C" void fn_27_CDEE0(Obj* p, u32 v) {
    p->b = v;
}
