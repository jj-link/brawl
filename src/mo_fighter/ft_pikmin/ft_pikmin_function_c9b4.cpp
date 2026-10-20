#pragma force_active on
#define SLOT(n) virtual void slot##n();
#define TEN(n) SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) SLOT(n##4) \
               SLOT(n##5) SLOT(n##6) SLOT(n##7) SLOT(n##8) SLOT(n##9)

struct Object {
    char padding[0x3C];
    TEN(0) TEN(1) TEN(2) TEN(3) TEN(4) TEN(5)
    TEN(6) TEN(7) TEN(8) TEN(9) TEN(10) TEN(11)
    TEN(12) TEN(13) TEN(14) TEN(15) TEN(16) TEN(17)
    SLOT(180) SLOT(181) SLOT(182) SLOT(183) SLOT(184) SLOT(185)
    virtual void method();
};

#undef TEN
#undef SLOT

extern "C" void fn_113_C9B4(Object* object) {
    object->method();
}
