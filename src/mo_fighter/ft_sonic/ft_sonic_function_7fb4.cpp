#pragma force_active on
extern "C" void fn_123_6D30(void* object, unsigned int value);
extern "C" char lbl_123_data_179C[0x70];

struct FtSonicWork {
    void* vtable;        // +0x00
    unsigned int pad04;  // +0x04
    void* vtablePrimary; // +0x08
    unsigned int a0c;    // +0x0C
    unsigned int a10;    // +0x10
    unsigned int a14;    // +0x14
    unsigned int a18;    // +0x18
    unsigned int a1c;    // +0x1C
    unsigned int a20;    // +0x20
};

extern "C" FtSonicWork* fn_123_7FB4(FtSonicWork* work, unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, unsigned int g) {
    fn_123_6D30(work, 0);
    work->vtablePrimary = lbl_123_data_179C;
    work->vtable = lbl_123_data_179C + 8;
    work->a0c = a;
    work->a10 = b;
    work->a14 = c;
    work->a18 = d;
    work->a1c = e;
    work->a20 = f;
    return work;
}
