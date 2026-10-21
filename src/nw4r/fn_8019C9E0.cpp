#pragma force_active on
extern "C" {

struct Inner {
    unsigned char unk[0x32];
    unsigned short value;
};

struct Outer {
    unsigned char unk[0x20];
    Inner *inner;
};

unsigned short fn_8019C9E0(Outer *arg) {
    return arg->inner->value;
}

}
