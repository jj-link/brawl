#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 pad0;
    u32 pad1;
    u32 a : 8;
    s32 field : 4;
    u32 rest : 20;
};

extern "C" s32 fn_27_264A48(Obj* p);

s32 fn_27_264A48(Obj* p) {
    return p->field;
}
