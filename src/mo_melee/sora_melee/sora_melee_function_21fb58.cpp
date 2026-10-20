#pragma force_active on
struct FlagOwner {
    char pad[0x16c];
    unsigned int flags;
};

extern "C" unsigned int fn_27_21FB58(FlagOwner **self, unsigned int bit) {
    FlagOwner *o = *self;
    unsigned int v = o->flags & (1u << bit);
    return (v != 0);
}
