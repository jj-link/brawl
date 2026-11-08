#pragma force_active on

extern "C" void* fn_41_3DBB8(void*, int);

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual int slot20();
};

struct Frame {
    unsigned char b[0x22];
};

extern "C" int fn_41_3D3F4(char* obj, int unused, unsigned int kind) {
    Frame f;
    unsigned char* buf = f.b;
    switch (kind) {
    case 0: {
        int r;
        buf[0x20] = 0;
        buf[0x21] = 0;
        for (int i = 0; i < 3; i++) {
            if (((soNullable*)fn_41_3DBB8(obj + 0xc, i))->slot20() == 0) {
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
