#pragma force_active on
struct St49 {
    unsigned char pad[0x6c];
    unsigned char flags;
};

extern "C" void fn_49_18D0(St49 *p) {
    p->flags |= 0x8;
}
