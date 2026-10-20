#pragma force_active on
typedef unsigned int u32;

struct BitfieldObj {
    u32 unk0;
    u32 unk4;
    u32 top : 5;
    u32 rest : 27;
};

extern "C" void fn_27_19BC08(BitfieldObj* obj, u32 val) {
    obj->top = val;
}
