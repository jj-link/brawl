#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 4;
    u32 b : 28;
};

extern "C" void fn_27_38D7C(void* self, u32 v) {
    Flags* f = (Flags*)((char*)self + 8);
    f->a = v;
}
