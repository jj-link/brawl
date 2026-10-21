#pragma force_active on
struct Inner {
    char pad[0x16];
    unsigned char value;
};

struct Outer {
    Inner* ptr;
};

extern "C" unsigned char fn_80153D10(Outer* self) {
    if (self->ptr == 0) {
        return 4;
    }
    return self->ptr->value;
}
