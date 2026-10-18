#pragma force_active on
struct ZeldaWork {
    void* vt00;
    unsigned int f04;
    void* data08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
};

extern "C" void fn_104_7858(void* obj, unsigned char kind);
extern "C" unsigned char lbl_104_data_2440[];

extern "C" ZeldaWork* fn_104_8ADC(ZeldaWork* work, unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, unsigned int g) {
    fn_104_7858(work, 0);
    work->data08 = lbl_104_data_2440;
    work->vt00 = lbl_104_data_2440 + 8;
    work->f0c = a;
    work->f10 = b;
    work->f14 = c;
    work->f18 = d;
    work->f1c = e;
    work->f20 = f;
    return work;
}
