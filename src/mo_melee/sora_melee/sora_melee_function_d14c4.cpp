#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 unk0;
    u32 unk4;
    u32 flag : 5;
    u32 rest : 27;
};

extern "C" void fn_27_D14C4(Bits* p, u32 v) {
    p->flag = v;
}
