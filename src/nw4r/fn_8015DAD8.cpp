#pragma force_active on
extern "C" {

struct fn_8015DAD8_inner {
    unsigned char pad[0x8];
    unsigned short value;
};

struct fn_8015DAD8_outer {
    unsigned char pad[0x10];
    fn_8015DAD8_inner *inner;
};

unsigned short fn_8015DAD8(fn_8015DAD8_outer *arg) {
    return arg->inner->value;
}

}
