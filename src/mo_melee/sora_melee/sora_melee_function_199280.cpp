#pragma force_active on
typedef unsigned int u32;

struct BitfieldHolder {
    char pad[8];
    u32 a : 6;
    u32 f : 6;
    u32 b : 20;
};

extern "C" void fn_27_199280(BitfieldHolder* p, u32 v) {
    p->f = v;
}
