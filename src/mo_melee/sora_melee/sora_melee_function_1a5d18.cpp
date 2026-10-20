#pragma force_active on
typedef unsigned int u32;

struct BitfieldHolder {
    u32 pad0;
    u32 pad1;
    u32 top : 10;
    u32 rest : 22;
};

extern "C" void fn_27_1A5D18(BitfieldHolder* p, u32 v) {
    p->top = v;
}
