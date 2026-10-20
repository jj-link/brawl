#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 3;
    u32 b : 3;
    u32 rest : 26;
};

extern "C" void fn_27_C98EC(void* self, u32 v) {
    Bits* w = (Bits*)((char*)self + 8);
    w->b = v;
}
