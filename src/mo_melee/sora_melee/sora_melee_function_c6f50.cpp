#pragma force_active on
typedef unsigned int u32;

struct FooBits {
    u32 a;
    u32 b;
    u32 f : 5;
    u32 rest : 27;
};

extern "C" void fn_27_C6F50(FooBits* p, u32 v) {
    p->f = v;
}
