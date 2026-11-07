#pragma force_active on
extern "C" void* fn_41_4DD90(char* p, int n);
class Object_vptr_0 {
public:
    virtual void slot0();
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
extern "C" int fn_41_4D5CC(char* obj, int unused, unsigned int kind) {
    int r;
    int i;
    Frame f;
    unsigned char* buf = f.b;
    switch (kind) {
    case 0:
        buf[0x20] = 0;
        buf[0x21] = 0;
        for (i = 0; i < 5; i++) {
            if (((Object_vptr_0*)fn_41_4DD90(obj + 0xc, i))->slot20() == 0) {
                r = 0;
                goto done;
            }
        }
        r = 1;
    done:
        return !r;
    case 1: buf[0x1e] = 0; buf[0x1f] = 0; return 0;
    case 2: buf[0x1c] = 0; buf[0x1d] = 0; return 0;
    case 3: buf[0x1a] = 0; buf[0x1b] = 0; return 0;
    case 4: buf[0x18] = 0; buf[0x19] = 0; return 0;
    case 5: buf[0x16] = 0; buf[0x17] = 0; return 0;
    case 6: buf[0x14] = 0; buf[0x15] = 0; return 0;
    case 7: buf[0x12] = 0; buf[0x13] = 0; return 0;
    case 8: buf[0x10] = 0; buf[0x11] = 0; return 0;
    case 9: buf[0xe] = 0; buf[0xf] = 0; return 0;
    case 10: buf[0xc] = 0; buf[0xd] = 0; return 0;
    case 11: buf[0xa] = 0; buf[0xb] = 0; return 0;
    case 12: buf[0x8] = 0; buf[0x9] = 0; return 0;
    case 13: buf[0x6] = 0; buf[0x7] = 0; return 0;
    case 14: buf[0x4] = 0; buf[0x5] = 0; return 0;
    case 15: buf[0x2] = 0; buf[0x3] = 0; return 0;
    case 16: buf[0x0] = 0; buf[0x1] = 0; return 0;
    default: return 0;
    }
}
