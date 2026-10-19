#pragma force_active on
struct Fn27Obj {
    char pad0[0x49];
    unsigned char b49;
    char pad1[0x4d - 0x4a];
    bool b4d;
    char pad2[0x5c - 0x4e];
    int i5c;
};

extern "C" {
extern unsigned int lbl_27_bss_59C0;

void fn_27_254D9C(Fn27Obj* self) {
    if (self->b4d) {
        return;
    }
    if (self->b49 == 0) {
        return;
    }
    if (lbl_27_bss_59C0 == 0) {
        return;
    }
    self->b4d = (self->i5c == 2);
}
}
