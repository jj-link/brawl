#pragma force_active on
typedef unsigned int u32;

struct fn_27_1A47E4_Obj {
    char pad[8];
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

extern "C" {
void fn_27_1A47E4(fn_27_1A47E4_Obj* obj, u32 val) {
    obj->b = val;
}
}
