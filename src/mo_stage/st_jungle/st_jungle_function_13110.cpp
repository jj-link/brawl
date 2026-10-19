#pragma force_active on
struct ObjectData {
    unsigned char padding[0x3C];
};

struct Object : ObjectData {
#define SLOT(n) virtual void slot##n();
#define TEN(n) \
    SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) SLOT(n##4) \
    SLOT(n##5) SLOT(n##6) SLOT(n##7) SLOT(n##8) SLOT(n##9)

    TEN(0)
    TEN(1)
    TEN(2)
    TEN(3)
    TEN(4)
    TEN(5)
    TEN(6)
    TEN(7)
    TEN(8)
    SLOT(90)
    SLOT(91)
    SLOT(92)
    SLOT(93)
    SLOT(94)
    SLOT(95)
    SLOT(96)

#undef TEN
#undef SLOT

    virtual void method(int, int);
};

extern "C" void fn_51_13110(Object* self)
{
    self->method(0, 0);
}
