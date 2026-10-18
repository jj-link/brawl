#pragma force_active on
extern "C" void fn_126_50F0(void* self, unsigned char value);
extern "C" char lbl_126_data_E1C[];

struct FtZakoWork {
    void* vtSecondary;    // +0x00
    unsigned char isNull; // +0x04
    void* vtPrimary;      // +0x08
    int w0;               // +0x0C
    int w1;               // +0x10
    int w2;               // +0x14
    int w3;               // +0x18
    int w4;               // +0x1C
    int w5;               // +0x20
};

extern "C" void* fn_126_62D8(void* self, int a, int b, int c, int d, int e, int f) {
    FtZakoWork* work = (FtZakoWork*)self;
    fn_126_50F0(self, 0);
    work->vtPrimary = lbl_126_data_E1C;
    work->vtSecondary = lbl_126_data_E1C + 8;
    work->w0 = a;
    work->w1 = b;
    work->w2 = c;
    work->w3 = d;
    work->w4 = e;
    work->w5 = f;
    return self;
}
