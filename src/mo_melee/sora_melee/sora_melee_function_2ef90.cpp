#pragma force_active on
struct fn27Inner {
    char pad[0x72];
    unsigned char flag;
};

struct fn27Outer {
    int pad;
    fn27Inner* inner;
};

extern "C" int fn_27_2EF90(fn27Outer* self) {
    return self->inner->flag & 1;
}
