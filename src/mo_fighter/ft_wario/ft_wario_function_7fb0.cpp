#pragma force_active on
extern "C" void fn_110_6D2C(void* obj, unsigned char flag);
extern "C" char lbl_110_data_16C8[];

struct Ft110Work {
    void* vtPrimary;    // +0x00
    void* vtSecondary;  // +0x04 (unused)
    void* vtBase;       // +0x08
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
};

extern "C" Ft110Work* fn_110_7FB0(Ft110Work* self, int a, int b, int c, int d, int e, int f) {
    fn_110_6D2C(self, 0);
    self->vtBase = lbl_110_data_16C8;
    self->vtPrimary = lbl_110_data_16C8 + 8;
    self->f0C = a;
    self->f10 = b;
    self->f14 = c;
    self->f18 = d;
    self->f1C = e;
    self->f20 = f;
    return self;
}
