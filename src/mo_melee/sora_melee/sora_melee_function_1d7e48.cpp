#pragma force_active on
typedef unsigned int u32;

struct Obj {
    char pad[8];
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
};

extern "C" void fn_27_1D7E48(Obj* obj, u32 val) {
    obj->b = val;
}
