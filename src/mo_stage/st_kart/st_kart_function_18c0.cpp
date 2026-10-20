#pragma force_active on
struct StKartFlagsHolder {
    char pad[0x6c];
    unsigned char flags;
};

extern "C" {
void fn_49_18C0(StKartFlagsHolder *p) {
    p->flags &= ~0x08;
}
}
