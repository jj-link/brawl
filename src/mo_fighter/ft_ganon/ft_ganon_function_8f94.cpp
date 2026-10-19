#pragma force_active on
#define VIRTUAL_SLOTS(n) \
    virtual void slot##n##0(); \
    virtual void slot##n##1(); \
    virtual void slot##n##2(); \
    virtual void slot##n##3(); \
    virtual void slot##n##4(); \
    virtual void slot##n##5(); \
    virtual void slot##n##6(); \
    virtual void slot##n##7(); \
    virtual void slot##n##8(); \
    virtual void slot##n##9();

class Object {
    unsigned char padding[0x3C];

public:
    VIRTUAL_SLOTS(0)
    VIRTUAL_SLOTS(1)
    VIRTUAL_SLOTS(2)
    VIRTUAL_SLOTS(3)
    VIRTUAL_SLOTS(4)
    VIRTUAL_SLOTS(5)
    VIRTUAL_SLOTS(6)
    VIRTUAL_SLOTS(7)
    VIRTUAL_SLOTS(8)
    VIRTUAL_SLOTS(9)
    VIRTUAL_SLOTS(10)
    VIRTUAL_SLOTS(11)
    VIRTUAL_SLOTS(12)
    VIRTUAL_SLOTS(13)
    VIRTUAL_SLOTS(14)
    VIRTUAL_SLOTS(15)
    VIRTUAL_SLOTS(16)
    VIRTUAL_SLOTS(17)
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void target();
};

#undef VIRTUAL_SLOTS

extern "C" void fn_109_8F94(Object* self) {
    self->target();
}
