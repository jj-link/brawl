#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct MetaKnightHeaderData {
    u8 padding[8];
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
    virtual void initialize();
};

struct MetaKnightObject {
    u8 padding[0x134];
    u8 data[0x80];
    u8 extra[0xC];
    MetaKnightHeaderData header;
};

extern "C" MetaKnightHeaderData* fn_111_7048(
    MetaKnightHeaderData*, s32, s32, s32, s32, s32, s32);

extern "C" MetaKnightObject* fn_111_7548(MetaKnightObject* self) {
    fn_111_7048(&self->header, reinterpret_cast<s32>(self), 0x4D,
                reinterpret_cast<s32>(self->data), 0x20,
                reinterpret_cast<s32>(self->extra), 3);
    self->header.initialize();
    return self;
}
