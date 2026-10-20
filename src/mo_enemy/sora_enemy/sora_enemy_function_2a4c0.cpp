#pragma force_active on
struct Src {
    char pad[0x14];
    unsigned char val;
};

struct Dst {
    Src* src;
    unsigned char val;
};

extern "C" void fn_41_2A4C0(Dst* dst, Src* src) {
    dst->src = src;
    dst->val = src->val;
}
