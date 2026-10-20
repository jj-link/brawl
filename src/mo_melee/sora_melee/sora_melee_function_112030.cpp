#pragma force_active on
struct Inner {
    unsigned char pad[0x20];
    unsigned char a : 2;
    unsigned char flag : 1;
    unsigned char b : 5;
};

struct Outer {
    Inner* inner;
};

extern "C" {
bool fn_27_112030(Outer* o) {
    return o->inner->flag;
}
}
