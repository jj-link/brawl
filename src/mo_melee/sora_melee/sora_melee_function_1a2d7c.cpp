#pragma force_active on
typedef unsigned int u32;

struct BitfieldStruct {
    u32 pad0;
    u32 pad1;
    u32 a : 2;
    u32 b : 2;
    u32 rest : 28;
};

extern "C" {
void fn_27_1A2D7C(BitfieldStruct* p, u32 v) {
    p->b = v;
}
}
