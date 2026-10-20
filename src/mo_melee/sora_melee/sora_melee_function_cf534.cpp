#pragma force_active on
struct FlagHolder {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int flags;
};

extern "C" void fn_27_CF534(FlagHolder* p) {
    p->flags &= ~0x2000u;
}
