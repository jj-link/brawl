#pragma force_active on
typedef unsigned int u32;

struct BitfieldHolder {
    char pad[8];
    u32 hi : 2;
    u32 rest : 30;
};

extern "C" void fn_27_CC164(BitfieldHolder* p, u32 v) {
    p->hi = v;
}
