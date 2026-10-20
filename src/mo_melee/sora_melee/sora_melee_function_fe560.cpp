#pragma force_active on
struct FnS27 {
    unsigned int pad[2];
    unsigned int flags;
};

extern "C" void fn_27_FE560(FnS27* p) {
    p->flags &= ~0x00400000u;
}
