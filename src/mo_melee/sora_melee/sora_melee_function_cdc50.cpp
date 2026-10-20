#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 rest : 5;
    u32 f : 5;
    u32 pad : 22;
};

extern "C" {
void fn_27_CDC50(void* p, u32 v) {
    Bits* b = (Bits*)((char*)p + 8);
    b->f = v;
}
}
