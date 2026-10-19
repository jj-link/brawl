#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Words3 {
    u32 a, b, c;
};

struct Words2 {
    u32 a, b;
};

struct Record {
    float f00, f04, f08, f0c;
    Words3 w10;
    u32 w1c;
    Words3 w20;
    u16 h2c, h2e;
    u8 b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b3a;
    u32 w3c;
    Words3 w40;
    float f4c;
    u32 w50, w54, w58, w5c;
    float f60, f64, f68;
    u32 w6c, w70, w74, w78;
    float f7c;
    Words3 w80;
    Words2 w8c;
    float f94;
    u32 w98;
    u8 b9c;
};

struct Container {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void slot18() = 0;
    virtual void slot19() = 0;
    virtual void slot20() = 0;
    virtual void slot21() = 0;
    virtual void slot22() = 0;
    virtual void slot23() = 0;
    virtual void slot24() = 0;
    virtual void slot25() = 0;
    virtual Record* get(int) = 0;
};

extern "C" void fn_74_788C(Container* self, int from, int to) {
    Record* source = self->get(from);
    Record* destination = self->get(to);
    *destination = *source;
}
