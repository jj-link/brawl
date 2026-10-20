#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad[2];
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
};

extern "C" void fn_27_1CF7A4(Bits* p, u32 v) {
    p->b = v;
}
