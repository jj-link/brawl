#pragma force_active on
typedef unsigned long u32;

struct Bits {
    u32 hi : 7;
    u32 f : 3;
    u32 lo : 22;
};

extern "C" {
void fn_800B9488(char* p, int idx, u32 v) {
    struct Bits* q = (struct Bits*)(*(char**)(p + 0xc) + idx * 0x48);
    q->f = v;
}
}
