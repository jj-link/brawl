#pragma force_active on
#define VTABLE_SLOTS(N) \
    virtual void slot##N##0(); \
    virtual void slot##N##1(); \
    virtual void slot##N##2(); \
    virtual void slot##N##3(); \
    virtual void slot##N##4(); \
    virtual void slot##N##5(); \
    virtual void slot##N##6(); \
    virtual void slot##N##7(); \
    virtual void slot##N##8(); \
    virtual void slot##N##9();

class Object {
    unsigned char padding[0x3C];

public:
    VTABLE_SLOTS(0)
    VTABLE_SLOTS(1)
    VTABLE_SLOTS(2)
    VTABLE_SLOTS(3)
    VTABLE_SLOTS(4)
    VTABLE_SLOTS(5)
    VTABLE_SLOTS(6)
    VTABLE_SLOTS(7)
    VTABLE_SLOTS(8)
    VTABLE_SLOTS(9)
    VTABLE_SLOTS(10)
    VTABLE_SLOTS(11)
    VTABLE_SLOTS(12)
    VTABLE_SLOTS(13)
    VTABLE_SLOTS(14)
    VTABLE_SLOTS(15)
    VTABLE_SLOTS(16)
    VTABLE_SLOTS(17)
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void callback();
};

#undef VTABLE_SLOTS

extern "C" void fn_105_DA78(Object* object) {
    object->callback();
}
