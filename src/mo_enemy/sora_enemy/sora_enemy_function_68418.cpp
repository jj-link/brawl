#pragma force_active on

extern "C" void* fn_41_68BDC(void*, int);

struct Obj {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual int unk58();
};

struct Frame {
    unsigned char b[0x22];
};

extern "C" int fn_41_68418(char* obj, int unused, unsigned int kind) {
    Frame f;
    unsigned char* buf = f.b;
    switch (kind) {
    case 0: {
        int r;
        buf[0x20] = 0;
        buf[0x21] = 0;
        for (int i = 0; i < 6; i++) {
            if (((Obj*)fn_41_68BDC(obj + 0xc, i))->unk58() == 0) {
                r = 0;
                goto done;
            }
        }
        r = 1;
    done:
        return r == 0;
    }
    case 1: buf[0x1E] = 0; buf[0x1F] = 0; return 0;
    case 2: buf[0x1C] = 0; buf[0x1D] = 0; return 0;
    case 3: buf[0x1A] = 0; buf[0x1B] = 0; return 0;
    case 4: buf[0x18] = 0; buf[0x19] = 0; return 0;
    case 5: buf[0x16] = 0; buf[0x17] = 0; return 0;
    case 6: buf[0x14] = 0; buf[0x15] = 0; return 0;
    case 7: buf[0x12] = 0; buf[0x13] = 0; return 0;
    case 8: buf[0x10] = 0; buf[0x11] = 0; return 0;
    case 9: buf[0xE] = 0; buf[0xF] = 0; return 0;
    case 10: buf[0xC] = 0; buf[0xD] = 0; return 0;
    case 11: buf[0xA] = 0; buf[0xB] = 0; return 0;
    case 12: buf[0x8] = 0; buf[0x9] = 0; return 0;
    case 13: buf[0x6] = 0; buf[0x7] = 0; return 0;
    case 14: buf[0x4] = 0; buf[0x5] = 0; return 0;
    case 15: buf[0x2] = 0; buf[0x3] = 0; return 0;
    case 16: buf[0x0] = 0; buf[0x1] = 0; return 0;
    default: return 0;
    }
}
