#include <types.h>
#pragma force_active on

class soWorkA {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual float getValue(u32 id);
};

struct soPadBase {
    u32 m_pad0;
    u32 m_pad1;
};

class soWorkB : public soPadBase {
public:
    virtual void w00();
    virtual void w01();
    virtual void w02();
    virtual void w03();
    virtual void w04();
    virtual void w05();
    virtual void w06();
    virtual void w07();
    virtual void w08();
    virtual void w09();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w50();
    virtual void w51();
    virtual void w52();
    virtual void w53();
    virtual void w54();
    virtual void setValue(float v);
};

class soFooWork {
public:
    u8 pad0[0xa04];
    soWorkB m_b;
    u8 pad1[0x2aac - 0xa04 - sizeof(soWorkB)];
    soWorkA m_a;
};

extern "C" {
void fn_27_28F8FC(soFooWork* self, float f) {
    float r = self->m_a.getValue(0x1100000c);
    self->m_b.setValue(f * r);
}
}
