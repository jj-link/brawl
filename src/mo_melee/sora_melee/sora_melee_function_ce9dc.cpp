#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 6;
    u32 b : 6;
    u32 c : 20;
};

extern "C" void fn_27_CE9DC(Flags* p, u32 v) {
    p[2].b = v;
}
