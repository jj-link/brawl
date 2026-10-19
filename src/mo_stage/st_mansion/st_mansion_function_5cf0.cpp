#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Triple {
    float x, y, z;
};

struct Pair {
    float x, y;
};

struct Entry {
    float f00, f04, f08, f0C;
    Triple v10;
    u32 i1C;
    Triple v20;
    u16 h2C, h2E;
    u8 b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b3A;
    u32 i3C;
    Triple v40;
    float f4C;
    u32 i50, i54, i58, i5C;
    float f60, f64, f68;
    u32 i6C, i70, i74, i78;
    float f7C;
    Triple v80;
    Pair v8C;
    float f94;
    u32 i98;
    u8 b9C;
};

struct Array {
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
    virtual Entry* at(int);
};

extern "C" void fn_47_5CF0(Array* self, int sourceIndex, int destinationIndex) {
    Entry* source = self->at(sourceIndex);
    Entry* destination = self->at(destinationIndex);
    *destination = *source;
}
