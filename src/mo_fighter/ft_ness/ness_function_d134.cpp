#pragma force_active on
#define NESS_VIRTUAL_TEN(n) \
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

struct NessCallbackObject {
    unsigned char padding[0x3C];

    NESS_VIRTUAL_TEN(0)
    NESS_VIRTUAL_TEN(1)
    NESS_VIRTUAL_TEN(2)
    NESS_VIRTUAL_TEN(3)
    NESS_VIRTUAL_TEN(4)
    NESS_VIRTUAL_TEN(5)
    NESS_VIRTUAL_TEN(6)
    NESS_VIRTUAL_TEN(7)
    NESS_VIRTUAL_TEN(8)
    NESS_VIRTUAL_TEN(9)
    NESS_VIRTUAL_TEN(10)
    NESS_VIRTUAL_TEN(11)
    NESS_VIRTUAL_TEN(12)
    NESS_VIRTUAL_TEN(13)
    NESS_VIRTUAL_TEN(14)
    NESS_VIRTUAL_TEN(15)
    NESS_VIRTUAL_TEN(16)
    NESS_VIRTUAL_TEN(17)
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void callback();
};

#undef NESS_VIRTUAL_TEN

extern "C" void fn_101_D134(NessCallbackObject* object) {
    object->callback();
}
