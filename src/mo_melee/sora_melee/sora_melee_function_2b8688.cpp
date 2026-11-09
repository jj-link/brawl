#include <types.h>
#pragma force_active on

class IfaceA {
public:
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8(u8 flag);
};

class IfaceB {
public:
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
};

struct FlagByte {
    u8 bit7 : 1;
    u8 rest : 7;
};

extern "C" void fn_27_2B8688(void* arg) {
    u8* self = (u8*)arg;
    ((FlagByte*)(self + 0x91))->bit7 = 0;
    u8 v91 = self[0x91];
    ((FlagByte*)(self + 0xDD))->bit7 = 0;
    ((IfaceA*)(self + 0x40))->m8(v91);
    ((FlagByte*)(self + 0x45))->bit7 = 0;
    ((IfaceA*)(self + 0xF8))->m7();
    ((FlagByte*)(self + 0xFD))->bit7 = 0;
    ((IfaceA*)(self + 0x130))->m7();
    ((FlagByte*)(self + 0x135))->bit7 = 0;
    ((IfaceB*)(self + 0x168))->m8();
    ((FlagByte*)(self + 0x16D))->bit7 = 0;
    ((IfaceA*)(self + 0x1B4))->m7();
    ((IfaceA*)(self + 0x200))->m7();
    ((FlagByte*)(self + 0x205))->bit7 = 0;
    ((IfaceA*)(self + 0x250))->m7();
    ((FlagByte*)(self + 0x255))->bit7 = 0;
    ((IfaceA*)(self + 0x280))->m7();
    ((FlagByte*)(self + 0x285))->bit7 = 0;
}
