#pragma force_active on
#define DECLARE_TEN(n)           \
    virtual void unused##n##0(); \
    virtual void unused##n##1(); \
    virtual void unused##n##2(); \
    virtual void unused##n##3(); \
    virtual void unused##n##4(); \
    virtual void unused##n##5(); \
    virtual void unused##n##6(); \
    virtual void unused##n##7(); \
    virtual void unused##n##8(); \
    virtual void unused##n##9();

struct Object {
    unsigned char padding[0x3C];

    DECLARE_TEN(0)
    DECLARE_TEN(1)
    DECLARE_TEN(2)
    DECLARE_TEN(3)
    DECLARE_TEN(4)
    DECLARE_TEN(5)
    DECLARE_TEN(6)
    DECLARE_TEN(7)
    DECLARE_TEN(8)
    DECLARE_TEN(9)
    DECLARE_TEN(10)
    DECLARE_TEN(11)
    DECLARE_TEN(12)
    DECLARE_TEN(13)
    DECLARE_TEN(14)
    DECLARE_TEN(15)
    DECLARE_TEN(16)
    DECLARE_TEN(17)

    virtual void unused180();
    virtual void unused181();
    virtual void unused182();
    virtual void unused183();
    virtual void unused184();
    virtual void unused185();
    virtual void dispatch();
};

#undef DECLARE_TEN

extern "C" void fn_122_F4EC(Object* object)
{
    object->dispatch();
}
