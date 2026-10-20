#pragma force_active on
#define VIRTUAL_SLOT(n) virtual void slot##n();
#define VIRTUAL_TEN(n) \
    VIRTUAL_SLOT(n##0) \
    VIRTUAL_SLOT(n##1) \
    VIRTUAL_SLOT(n##2) \
    VIRTUAL_SLOT(n##3) \
    VIRTUAL_SLOT(n##4) \
    VIRTUAL_SLOT(n##5) \
    VIRTUAL_SLOT(n##6) \
    VIRTUAL_SLOT(n##7) \
    VIRTUAL_SLOT(n##8) \
    VIRTUAL_SLOT(n##9)

class Object {
    unsigned char padding[0x3c];

public:
    VIRTUAL_TEN(0)
    VIRTUAL_TEN(1)
    VIRTUAL_TEN(2)
    VIRTUAL_TEN(3)
    VIRTUAL_TEN(4)
    VIRTUAL_TEN(5)
    VIRTUAL_TEN(6)
    VIRTUAL_TEN(7)
    VIRTUAL_TEN(8)
    VIRTUAL_TEN(9)
    VIRTUAL_TEN(10)
    VIRTUAL_TEN(11)
    VIRTUAL_TEN(12)
    VIRTUAL_SLOT(130)
    VIRTUAL_SLOT(131)
    VIRTUAL_SLOT(132)
    VIRTUAL_SLOT(133)
    VIRTUAL_SLOT(134)
    VIRTUAL_SLOT(135)
    VIRTUAL_SLOT(136)
    VIRTUAL_SLOT(137)
    VIRTUAL_SLOT(138)

    virtual void first();
    virtual void second(float);
};

#undef VIRTUAL_TEN
#undef VIRTUAL_SLOT

extern "C" void fn_67_11D4(Object* self, float value) {
    self->first();
    self->second(value);
}
