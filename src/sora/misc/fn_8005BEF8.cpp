#pragma force_active on
typedef unsigned short u16;

struct Inner {
    unsigned char pad0[0xc];
    u16 unitC;
    unsigned char pad1[0x18 - 0xe];
    u16 unit18;
};

struct Outer {
    unsigned char pad[0x24];
    Inner *inner;
};

extern "C" {
int fn_8005BEF8(Outer *arg0) {
    Inner *temp_r4 = arg0->inner;
    if (temp_r4 == 0) {
        return 0;
    }
    return temp_r4->unit18 + temp_r4->unitC;
}
}
