#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad[2];
    u32 a : 12;
    u32 f : 6;
    u32 b : 14;
};

extern "C" void fn_40_1E618(Obj* obj, u32 v) {
    obj->f = v;
}
