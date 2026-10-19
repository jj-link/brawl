#pragma force_active on
struct Fn48Entry {
    unsigned char pad[8];
    int flags;
};

extern "C" unsigned char* fn_48_B48C(Fn48Entry* self, int index) {
    int n = (self->flags >> 23) + index;
    if (n >= 0xCD) {
        n = n - 0xCD;
    }
    return (unsigned char*)self + n * 0xA0 + 0xC;
}
