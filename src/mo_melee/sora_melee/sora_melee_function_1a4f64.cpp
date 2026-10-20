#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad[2];
    u32 a : 4;
    u32 b : 2;
    u32 c : 26;
};

extern "C" void fn_27_1A4F64(Obj* obj, u32 val) {
    obj->b = val;
}
