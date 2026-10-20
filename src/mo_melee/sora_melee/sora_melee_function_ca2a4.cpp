#pragma force_active on
typedef unsigned int u32;

typedef struct Obj {
    char pad[8];
    u32 a : 5;
    u32 f : 5;
    u32 b : 22;
} Obj;

extern "C" void fn_27_CA2A4(Obj* obj, u32 val) {
    obj->f = val;
}
