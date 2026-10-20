#pragma force_active on
typedef unsigned int u32;

struct FnObj {
    char pad[8];
    u32 a : 6;
    u32 b : 3;
    u32 c : 23;
};

extern "C" {
void fn_27_FE5AC(FnObj* obj, u32 v) {
    obj->b = v;
}
}
