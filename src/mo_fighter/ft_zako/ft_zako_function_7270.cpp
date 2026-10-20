#pragma force_active on
#define DECLARE_TEN_SLOTS(n) \
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
public:
    unsigned char padding[0x3c];

    DECLARE_TEN_SLOTS(0)
    DECLARE_TEN_SLOTS(1)
    DECLARE_TEN_SLOTS(2)
    DECLARE_TEN_SLOTS(3)
    DECLARE_TEN_SLOTS(4)
    DECLARE_TEN_SLOTS(5)
    DECLARE_TEN_SLOTS(6)
    DECLARE_TEN_SLOTS(7)
    DECLARE_TEN_SLOTS(8)
    DECLARE_TEN_SLOTS(9)
    DECLARE_TEN_SLOTS(10)
    DECLARE_TEN_SLOTS(11)
    DECLARE_TEN_SLOTS(12)
    DECLARE_TEN_SLOTS(13)
    DECLARE_TEN_SLOTS(14)
    DECLARE_TEN_SLOTS(15)
    DECLARE_TEN_SLOTS(16)
    DECLARE_TEN_SLOTS(17)

    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void target();
};

#undef DECLARE_TEN_SLOTS

extern "C" void fn_126_7270(Object* self) {
    self->target();
}
