#pragma force_active on
struct FnObj40 {
    char pad[8];
    unsigned int flags;
};

extern "C" {
int fn_40_30B70(FnObj40* p) {
    return (int)((p->flags << 10) & 0xFC000000u) >> 27;
}
}
