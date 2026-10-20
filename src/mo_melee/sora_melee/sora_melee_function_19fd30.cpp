#pragma force_active on
typedef unsigned int u32;

struct BitfieldHolder {
    u32 unk0;
    u32 unk4;
    u32 mode : 3;
};

extern "C" void fn_27_19FD30(BitfieldHolder* p, u32 v) {
    p->mode = v;
}
