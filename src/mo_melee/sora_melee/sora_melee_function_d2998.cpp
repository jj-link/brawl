#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad[2];
    u32 a : 3;
    u32 b : 3;
    u32 c : 26;
};

extern "C" void fn_27_D2998(Obj *obj, u32 val) {
    obj->b = val;
}
