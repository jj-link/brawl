#pragma force_active on
struct Data {
    unsigned int field00;
    short field04;
    short field06;
    float field08;
    float field0C;
    unsigned int field10;
    float field14;
    float field18;
    unsigned int field1C;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2C;
    unsigned char field30;
    unsigned char field31;
    unsigned char field32;
    unsigned char field33;
    unsigned char field34;
};

struct Object {
    virtual void slot00() = 0;
    virtual void slot04() = 0;
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
    virtual void slot40() = 0;
    virtual void slot44() = 0;
    virtual void slot48() = 0;
    virtual void slot4C() = 0;
    virtual void slot50() = 0;
    virtual void slot54() = 0;
    virtual void slot58() = 0;
    virtual void slot5C() = 0;
    virtual void slot60() = 0;
    virtual void slot64() = 0;
    virtual Data* getData(int index) = 0;
};

extern "C" void fn_76_5770(Object* object, int first, int second) {
    Data* source = object->getData(first);
    Data* destination = object->getData(second);

    destination->field00 = source->field00;
    destination->field04 = source->field04;
    destination->field06 = source->field06;
    destination->field08 = source->field08;
    destination->field0C = source->field0C;
    destination->field10 = source->field10;
    destination->field14 = source->field14;
    destination->field18 = source->field18;
    destination->field1C = source->field1C;
    destination->field20 = source->field20;
    destination->field24 = source->field24;
    destination->field28 = source->field28;
    destination->field2C = source->field2C;
    destination->field30 = source->field30;
    destination->field31 = source->field31;
    destination->field32 = source->field32;
    destination->field33 = source->field33;
    destination->field34 = source->field34;
}
