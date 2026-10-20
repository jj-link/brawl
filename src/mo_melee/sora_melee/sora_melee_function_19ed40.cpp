#pragma force_active on
typedef unsigned int u32;

struct BitfieldHolder {
    u32 unk0;
    u32 unk4;
    u32 mode : 5;
    u32 rest : 27;
};

extern "C" void fn_27_19ED40(BitfieldHolder* p, u32 v) {
    p->mode = v;
}
