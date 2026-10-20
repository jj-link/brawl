#pragma force_active on
struct FnObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
int fn_48_B3D8(FnObj *p) {
    return ((int)((p->flags << 6) & 0xFE000000u)) >> 26;
}
}
