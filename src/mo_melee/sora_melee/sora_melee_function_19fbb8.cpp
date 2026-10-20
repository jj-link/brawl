#pragma force_active on
typedef unsigned int u32;

struct Obj {
    char pad[8];
    u32 hi : 3;
    u32 f : 3;
    u32 lo : 26;
};

extern "C" void fn_27_19FBB8(Obj* o, u32 v) {
    o->f = v;
}
