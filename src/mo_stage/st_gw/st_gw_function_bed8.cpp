#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Vec3 {
    float x, y, z;
};

struct Vec2 {
    float x, y;
};

struct Data {
    float f00, f04, f08, f0c;
    Vec3 v10;
    u32 w1c;
    Vec3 v20;
    u16 h2c, h2e;
    u8 b30, b31, b32, b33, b34, b35;
    u8 b36, b37, b38, b39, b3a;
    u32 w3c;
    Vec3 v40;
    float f4c;
    u32 w50, w54, w58, w5c;
    float f60, f64, f68;
    u32 w6c, w70, w74, w78;
    float f7c;
    Vec3 v80;
    Vec2 v8c;
    float f94;
    u32 w98;
    u8 b9c;
};

struct Object {
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
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual Data* getData(int);
};

extern "C" void fn_63_BED8(Object* self, int from, int to) {
    Data* src = self->getData(from);
    Data* dst = self->getData(to);
    *dst = *src;
}
