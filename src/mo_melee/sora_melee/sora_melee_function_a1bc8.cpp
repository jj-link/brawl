#pragma force_active on
typedef unsigned int u32;

struct FnBits {
    u32 pad[2];
    u32 bits : 5;
    u32 rest : 27;
};

extern "C" {
void fn_27_A1BC8(FnBits* p, u32 v) {
    p->bits = v;
}
}
