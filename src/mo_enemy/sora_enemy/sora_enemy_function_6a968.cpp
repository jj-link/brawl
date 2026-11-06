#pragma force_active on
extern "C" void* fn_41_6B12C(void*, int);
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
struct Frame { unsigned char b[0x22]; };
extern "C" int fn_41_6A968(char* obj, int unused, unsigned int kind) {
    Frame f;
    unsigned char* buf = f.b;
    switch (kind) {
    case 0: {
        int r;
        buf[0x20] = 0;
        buf[0x21] = 0;
        for (int i = 0; i < 20; i++) {
            if (((soNullable*)fn_41_6B12C(obj + 0xc, i))->slot20() == 0) {
                r = 0;
                goto done;
            }
        }
        r = 1;
    done:
        return r == 0;
    }
    case 1: buf[30] = 0; buf[31] = 0; return 0;
    case 2: buf[28] = 0; buf[29] = 0; return 0;
    case 3: buf[26] = 0; buf[27] = 0; return 0;
    case 4: buf[24] = 0; buf[25] = 0; return 0;
    case 5: buf[22] = 0; buf[23] = 0; return 0;
    case 6: buf[20] = 0; buf[21] = 0; return 0;
    case 7: buf[18] = 0; buf[19] = 0; return 0;
    case 8: buf[16] = 0; buf[17] = 0; return 0;
    case 9: buf[14] = 0; buf[15] = 0; return 0;
    case 10: buf[12] = 0; buf[13] = 0; return 0;
    case 11: buf[10] = 0; buf[11] = 0; return 0;
    case 12: buf[8] = 0; buf[9] = 0; return 0;
    case 13: buf[6] = 0; buf[7] = 0; return 0;
    case 14: buf[4] = 0; buf[5] = 0; return 0;
    case 15: buf[2] = 0; buf[3] = 0; return 0;
    case 16: buf[0] = 0; buf[1] = 0; return 0;
    default: return 0;
    }
}