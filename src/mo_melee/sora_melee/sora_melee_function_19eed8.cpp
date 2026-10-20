#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 5;
    u32 rest : 27;
};

extern "C" void fn_27_19EED8(void* p, u32 v) {
    Bits* b = (Bits*)((char*)p + 8);
    b->hi = v;
}
