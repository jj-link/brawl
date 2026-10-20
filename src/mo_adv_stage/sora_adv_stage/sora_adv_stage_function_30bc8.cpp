#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad[2];
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
} Obj;

extern "C" void fn_40_30BC8(Obj* obj, u32 val) {
    obj->b = val;
}
