#pragma force_active on
struct Unk {
    char pad[8];
    unsigned int flags;
};

extern "C" void fn_56_6700(Unk* p) {
    p->flags |= 0x80000;
}
