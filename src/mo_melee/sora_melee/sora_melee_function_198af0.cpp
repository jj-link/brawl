#pragma force_active on
typedef unsigned int u32;

struct FooBits {
    u32 pad[2];
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_198AF0(FooBits* p, u32 v) {
    p->hi = v;
}
