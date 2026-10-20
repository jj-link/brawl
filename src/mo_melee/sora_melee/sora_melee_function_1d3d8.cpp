#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct BitfieldObj {
    u8 pad[8];
    u32 mode : 2;
    u32 rest : 30;
};

extern "C" void fn_27_1D3D8(BitfieldObj* obj, u32 mode) {
    obj->mode = mode;
}
