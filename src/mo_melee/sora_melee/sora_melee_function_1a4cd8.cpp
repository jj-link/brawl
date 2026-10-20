#pragma force_active on
typedef unsigned int u32;

struct FnObj {
    u32 pad0;
    u32 pad1;
    u32 field : 5;
    u32 rest : 27;
};

extern "C" void fn_27_1A4CD8(FnObj* obj, u32 val) {
    obj->field = val;
}
