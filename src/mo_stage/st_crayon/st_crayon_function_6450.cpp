#pragma force_active on
struct Unk {
    char pad[8];
    unsigned int flags;
};

extern "C" void fn_56_6450(Unk* p) {
    p->flags &= ~0x02000000;
}
