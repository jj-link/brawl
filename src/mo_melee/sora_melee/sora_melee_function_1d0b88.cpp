#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

extern "C" {
void fn_27_1D0B88(void* self, u32 v) {
    Flags* f = (Flags*)((char*)self + 8);
    f->b = v;
}
}
