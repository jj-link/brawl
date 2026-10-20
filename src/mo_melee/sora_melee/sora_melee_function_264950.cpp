#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 4;
    u32 f : 2;
    u32 b : 26;
};

extern "C" void fn_27_264950(void* p, int v) {
    Bits* s = (Bits*)((char*)p + 8);
    s->f = v;
}
