#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 10;
    u32 b : 10;
    u32 c : 12;
};

extern "C" {
void fn_27_1A6044(void* self, u32 v) {
    Bits* p = (Bits*)((char*)self + 8);
    p->b = v;
}
}
