#pragma force_active on
typedef unsigned int u32;

struct Target {
    u32 unk0;
    u32 unk4;
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

extern "C" void fn_27_199488(Target* p, u32 v) {
    p->b = v;
}
