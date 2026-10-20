#pragma force_active on
#define VIRTUAL_TEN(prefix) \
    virtual void prefix##0(); \
    virtual void prefix##1(); \
    virtual void prefix##2(); \
    virtual void prefix##3(); \
    virtual void prefix##4(); \
    virtual void prefix##5(); \
    virtual void prefix##6(); \
    virtual void prefix##7(); \
    virtual void prefix##8(); \
    virtual void prefix##9();

struct Base {
    unsigned char padding[0x3C];
};

struct Object : Base {
    VIRTUAL_TEN(slot0_)
    VIRTUAL_TEN(slot1_)
    VIRTUAL_TEN(slot2_)
    VIRTUAL_TEN(slot3_)
    VIRTUAL_TEN(slot4_)
    VIRTUAL_TEN(slot5_)
    VIRTUAL_TEN(slot6_)
    VIRTUAL_TEN(slot7_)
    VIRTUAL_TEN(slot8_)
    VIRTUAL_TEN(slot9_)
    VIRTUAL_TEN(slot10_)
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void callback();

    unsigned char padding40[0x10C];
    int value;
    unsigned char padding150[0x51];
    unsigned char flag;
};

#undef VIRTUAL_TEN

extern "C" void fn_52_DA90(Object* self) {
    if (self->flag != 1) {
        self->callback();
        if (self->value != 0) {
            self->flag = 1;
        }
    }
}
