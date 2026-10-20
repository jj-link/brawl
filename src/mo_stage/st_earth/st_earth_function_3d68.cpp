#pragma force_active on
#define EARTH_VIRTUAL_SLOTS(n) \
    virtual void slot##n##0(); \
    virtual void slot##n##1(); \
    virtual void slot##n##2(); \
    virtual void slot##n##3(); \
    virtual void slot##n##4(); \
    virtual void slot##n##5(); \
    virtual void slot##n##6(); \
    virtual void slot##n##7(); \
    virtual void slot##n##8(); \
    virtual void slot##n##9(); \
    virtual void slot##n##A(); \
    virtual void slot##n##B(); \
    virtual void slot##n##C(); \
    virtual void slot##n##D(); \
    virtual void slot##n##E(); \
    virtual void slot##n##F();

struct EarthBase {
    unsigned char padding0[0x3C];

    EARTH_VIRTUAL_SLOTS(0)
    EARTH_VIRTUAL_SLOTS(1)
    EARTH_VIRTUAL_SLOTS(2)
    EARTH_VIRTUAL_SLOTS(3)
    EARTH_VIRTUAL_SLOTS(4)
    EARTH_VIRTUAL_SLOTS(5)
    EARTH_VIRTUAL_SLOTS(6)
    EARTH_VIRTUAL_SLOTS(7)
    virtual void slot80();
    virtual void initialize();
    virtual void update();
};

#undef EARTH_VIRTUAL_SLOTS

struct Earth : EarthBase {
    unsigned char padding1[0x11C];
    unsigned char initialized;
    unsigned char padding2[0x1C3];
    int state;
};

extern "C" void fn_66_3D68(Earth* self) {
    if (self->initialized == 1) {
        if (self->state == 1) {
            self->update();
        }
    } else {
        self->initialize();
        self->initialized = 1;
    }
}
