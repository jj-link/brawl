#pragma force_active on
#define DECLARE_TEN(n) \
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

struct Fighter {
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

    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void callback();
};

#undef DECLARE_TEN

extern "C" void fn_97_B08C(Fighter* fighter) {
    fighter->callback();
}
