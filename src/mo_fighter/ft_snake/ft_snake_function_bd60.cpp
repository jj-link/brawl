#pragma force_active on
extern "C" void fn_122_AADC(void* self, unsigned char val);
extern "C" void* lbl_122_data_81FC[28];

struct FtSnakeWork {
    void* vtSecondary;   // +0x00
    unsigned char pad;   // +0x04 (not written here)
    void* vtPrimary;     // +0x08
    int a;               // +0x0C
    int b;               // +0x10
    int c;               // +0x14
    int d;               // +0x18
    int e;               // +0x1C
    int f;               // +0x20
};

extern "C" FtSnakeWork* fn_122_BD60(FtSnakeWork* self, int a, int b, int c, int d, int e, int f) {
    fn_122_AADC(self, 0);
    self->vtPrimary = lbl_122_data_81FC;
    self->vtSecondary = &lbl_122_data_81FC[2];
    self->a = a;
    self->b = b;
    self->c = c;
    self->d = d;
    self->e = e;
    self->f = f;
    return self;
}
