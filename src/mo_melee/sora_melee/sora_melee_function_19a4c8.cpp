#pragma force_active on
typedef unsigned int u32;

struct BitfieldHolder {
    char pad[8];
    u32 top : 5;
    u32 rest : 27;
};

extern "C" {
void fn_27_19A4C8(BitfieldHolder* p, u32 v) {
    p->top = v;
}
}
