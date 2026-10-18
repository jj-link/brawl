#pragma force_active on
struct FnPad27 {
    char pad[0x538];
    unsigned int flags;
};

extern "C" {
bool fn_27_14CC78(FnPad27* self, unsigned int bit) {
    return (self->flags & (1u << bit)) != 0;
}
}
