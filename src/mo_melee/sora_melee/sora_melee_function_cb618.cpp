#pragma force_active on
typedef unsigned int u32;

struct BitfieldHolder {
    u32 pad[2];
    u32 field : 7;
    u32 rest : 25;
};

extern "C" void fn_27_CB618(BitfieldHolder* p, u32 v) {
    p->field = v;
}
