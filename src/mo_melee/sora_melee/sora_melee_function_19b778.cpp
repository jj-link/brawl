#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 f : 6;
    u32 rest : 26;
};

extern "C" void fn_27_19B778(unsigned char* p, u32 v) {
    Bits* b = (Bits*)(p + 8);
    b->f = v;
}
