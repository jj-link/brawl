#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 10;
    u32 b : 5;
    u32 c : 17;
};

extern "C" void fn_27_19B124(void* obj, u32 val) {
    Flags* f = (Flags*)((char*)obj + 8);
    f->b = val;
}
