#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad[2];
    u32 hi : 2;
    u32 rest : 30;
};

extern "C" void fn_27_CC9F8(Obj* obj, u32 val) {
    obj->hi = val;
}
