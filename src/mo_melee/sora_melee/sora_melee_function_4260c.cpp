#pragma force_active on
struct SoObj {
    unsigned char pad_00[0x20];
    int m20;
    void* m24;
    int m28;
    unsigned char pad_2c[5];
    unsigned char m31;
    unsigned char m32;
};

extern "C" void fn_27_4260C(SoObj* p) {
    unsigned int zero = 0;
    p->m31 = zero;
    if (p->m24 != 0) {
        p->m20 = 2;
        return;
    }
    if (p->m32 == 1 || p->m28 != 0) {
        p->m20 = 1;
    } else {
        p->m20 = 0;
    }
}
