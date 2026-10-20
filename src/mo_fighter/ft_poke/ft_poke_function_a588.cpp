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
    unsigned char padding[0x3C];

public:
    DECLARE_TEN_SLOTS(00)
    DECLARE_TEN_SLOTS(01)
    DECLARE_TEN_SLOTS(02)
    DECLARE_TEN_SLOTS(03)
    DECLARE_TEN_SLOTS(04)
    DECLARE_TEN_SLOTS(05)
    DECLARE_TEN_SLOTS(06)
    DECLARE_TEN_SLOTS(07)
    DECLARE_TEN_SLOTS(08)
    DECLARE_TEN_SLOTS(09)
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
    virtual void call();
};

#undef DECLARE_TEN_SLOTS

extern "C" void fn_116_A588(Object* object)
{
    object->call();
}
