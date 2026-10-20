#pragma force_active on
struct FnObj27 {
    char pad[0x54];
    unsigned int flags;
};

extern "C" {
bool fn_27_20B694(FnObj27 *p, unsigned int mask) {
    return (p->flags & mask) != 0;
}
}
