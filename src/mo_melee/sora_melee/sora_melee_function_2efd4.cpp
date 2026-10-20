#pragma force_active on
typedef unsigned char u8;

struct Inner {
    u8 pad[0x71];
    u8 flags;
};

struct Outer {
    int pad;
    Inner* inner;
};

extern "C" void fn_27_2EFD4(Outer* p) {
    Inner* i = p->inner;
    if (i == 0) {
        return;
    }
    i->flags |= 0x80;
}
