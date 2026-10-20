#pragma force_active on
typedef unsigned char u8;

struct Inner {
    u8 pad[0x1c];
    u8 flag7 : 1;
    u8 rest : 7;
};

struct Outer {
    u8 pad[0x10];
    Inner* inner;
};

extern "C" {
void fn_27_234DAC(Outer* self, int flag) {
    if (flag != 0) {
        self->inner->flag7 = 0;
    } else {
        self->inner->flag7 = 1;
    }
}
}
