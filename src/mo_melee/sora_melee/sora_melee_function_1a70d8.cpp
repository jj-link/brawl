#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad[2];
    u32 : 8;
    u32 value : 4;
    u32 : 20;
};

extern "C" void fn_27_1A70D8(Obj* p, u32 v) {
    p->value = v;
}
