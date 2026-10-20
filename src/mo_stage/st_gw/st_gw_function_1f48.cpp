#pragma force_active on
#define DECLARE_EIGHT_SLOTS(n) \
    virtual void unused##n##_0(); \
    virtual void unused##n##_1(); \
    virtual void unused##n##_2(); \
    virtual void unused##n##_3(); \
    virtual void unused##n##_4(); \
    virtual void unused##n##_5(); \
    virtual void unused##n##_6(); \
    virtual void unused##n##_7();

class Object {
    unsigned char padding[0x3C];

public:
    DECLARE_EIGHT_SLOTS(0)
    DECLARE_EIGHT_SLOTS(1)
    DECLARE_EIGHT_SLOTS(2)
    DECLARE_EIGHT_SLOTS(3)
    DECLARE_EIGHT_SLOTS(4)
    DECLARE_EIGHT_SLOTS(5)
    DECLARE_EIGHT_SLOTS(6)
    DECLARE_EIGHT_SLOTS(7)
    DECLARE_EIGHT_SLOTS(8)
    DECLARE_EIGHT_SLOTS(9)
    DECLARE_EIGHT_SLOTS(10)
    DECLARE_EIGHT_SLOTS(11)
    DECLARE_EIGHT_SLOTS(12)
    DECLARE_EIGHT_SLOTS(13)
    DECLARE_EIGHT_SLOTS(14)
    DECLARE_EIGHT_SLOTS(15)
    DECLARE_EIGHT_SLOTS(16)
    DECLARE_EIGHT_SLOTS(17)
    DECLARE_EIGHT_SLOTS(18)
    virtual void first();
    virtual void second(float);
};

#undef DECLARE_EIGHT_SLOTS

extern "C" void fn_63_1F48(Object* object, float value) {
    object->first();
    object->second(value);
}
