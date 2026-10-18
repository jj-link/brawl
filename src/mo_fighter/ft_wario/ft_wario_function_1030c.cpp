#pragma force_active on
extern "C" {

struct Inner {
    char pad1[0x20];
    int value;
};

struct Wario {
    char pad2[0xd8];
    Inner* inner;
};

int fn_110_1030C(Wario* self) {
    return self->inner->value;
}

}
