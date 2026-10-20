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
public:
    char padding[0x3C];
    VIRTUAL_SLOTS(00)
    VIRTUAL_SLOTS(01)
    VIRTUAL_SLOTS(02)
    VIRTUAL_SLOTS(03)
    VIRTUAL_SLOTS(04)
    VIRTUAL_SLOTS(05)
    VIRTUAL_SLOTS(06)
    VIRTUAL_SLOTS(07)
    VIRTUAL_SLOTS(08)
    VIRTUAL_SLOTS(09)
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
    virtual void callback();
};

#undef VIRTUAL_SLOTS

extern "C" void fn_104_A770(Object* object)
{
    object->callback();
}
