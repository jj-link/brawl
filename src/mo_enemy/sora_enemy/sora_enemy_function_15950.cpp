#pragma force_active on
typedef unsigned int u32;

struct Dst {
    char pad[0x24];
    u32 a;
    u32 b;
};

struct Src {
    u32 a;
    u32 b;
};

extern "C" void fn_41_15950(Dst* dst, Src* src) {
    dst->a = src->a;
    dst->b = src->b;
}
