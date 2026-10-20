#pragma force_active on
typedef unsigned int u32;

struct SoFlagsHolder {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_199D88(SoFlagsHolder* p) {
    p->flags |= 0x10000;
}
}
