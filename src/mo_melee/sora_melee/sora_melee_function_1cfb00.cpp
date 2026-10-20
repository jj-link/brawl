#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 12;
    u32 f : 6;
    u32 b : 14;
};

extern "C" void fn_27_1CFB00(void* p, u32 v) {
    Bits* s = (Bits*)((char*)p + 8);
    s->f = v;
}
