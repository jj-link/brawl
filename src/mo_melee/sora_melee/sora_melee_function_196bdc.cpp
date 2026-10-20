#pragma force_active on
struct Base {
    unsigned char padding[8];
};

struct Object : Base {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual unsigned int query(int);

    unsigned char padding1[8];
    float value;
};

extern "C" const float lbl_27_rodata_2700[];

extern "C" float fn_27_196BDC(Object* self) {
    if (self->query(0) == 1) {
        return self->value;
    }
    return lbl_27_rodata_2700[0];
}
