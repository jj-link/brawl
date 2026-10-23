#pragma force_active on
extern unsigned char* const __GXData;

typedef union {
    unsigned long w;
    struct {
        unsigned long c : 8;
        unsigned long pad : 4;
        unsigned long b : 10;
        unsigned long a : 10;
    } f;
} BPReg;

void fn_801F1564(unsigned long arg0, unsigned long arg1, unsigned long arg2, unsigned long arg3) {
    BPReg r1;
    BPReg r2;
    r1.w = 0;
    r1.f.a = arg0;
    r1.f.b = arg1;
    r1.f.c = 0x49;
    r2.w = 0;
    r2.f.a = arg2 - 1;
    r2.f.b = arg3 - 1;
    r2.f.c = 0x4A;
    *(unsigned long*)(__GXData + 0x240) = r1.w;
    *(unsigned long*)(__GXData + 0x244) = r2.w;
}
