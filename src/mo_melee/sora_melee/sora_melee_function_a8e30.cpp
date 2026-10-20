#pragma force_active on
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
    virtual int query(int);

    char padding[0x38];
    int value;
};

extern "C" bool fn_27_A8E30(Object* self) {
    int value = self->value;
    if (value == -1) {
        return true;
    }
    return self->query(value) != 1;
}
