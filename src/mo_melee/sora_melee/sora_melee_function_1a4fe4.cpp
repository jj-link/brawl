#pragma force_active on
typedef unsigned int u32;

struct BitfieldObj {
    u32 pad[2];
    u32 top : 5;
    u32 rest : 27;
};

extern "C" void fn_27_1A4FE4(BitfieldObj* obj, u32 value) {
    obj->top = value;
}
