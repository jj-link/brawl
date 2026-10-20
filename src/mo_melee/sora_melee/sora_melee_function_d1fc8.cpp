#pragma force_active on
typedef unsigned int u32;

struct fn27Obj {
    char pad[8];
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

extern "C" void fn_27_D1FC8(fn27Obj* obj, u32 v) {
    obj->b = v;
}
