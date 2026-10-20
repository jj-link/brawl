#pragma force_active on
typedef unsigned int u32;

struct fn_27_FE680_Obj {
    char pad[8];
    u32 top : 4;
    u32 rest : 28;
};

extern "C" {
void fn_27_FE680(fn_27_FE680_Obj* obj, u32 value) {
    obj->top = value;
}
}
