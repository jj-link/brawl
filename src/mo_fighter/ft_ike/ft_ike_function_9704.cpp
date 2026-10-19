#pragma force_active on
#define VIRTUAL_TEN(prefix) \
    virtual void prefix##0(); \
    virtual void prefix##1(); \
    virtual void prefix##2(); \
    virtual void prefix##3(); \
    virtual void prefix##4(); \
    virtual void prefix##5(); \
    virtual void prefix##6(); \
    virtual void prefix##7(); \
    virtual void prefix##8(); \
    virtual void prefix##9();

struct Object {
    unsigned char padding[0x3C];
    VIRTUAL_TEN(slot00_)
    VIRTUAL_TEN(slot01_)
    VIRTUAL_TEN(slot02_)
    VIRTUAL_TEN(slot03_)
    VIRTUAL_TEN(slot04_)
    VIRTUAL_TEN(slot05_)
    VIRTUAL_TEN(slot06_)
    VIRTUAL_TEN(slot07_)
    VIRTUAL_TEN(slot08_)
    VIRTUAL_TEN(slot09_)
    VIRTUAL_TEN(slot10_)
    VIRTUAL_TEN(slot11_)
    VIRTUAL_TEN(slot12_)
    VIRTUAL_TEN(slot13_)
    VIRTUAL_TEN(slot14_)
    VIRTUAL_TEN(slot15_)
    VIRTUAL_TEN(slot16_)
    VIRTUAL_TEN(slot17_)
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void target();
};

#undef VIRTUAL_TEN

extern "C" void fn_119_9704(Object* self) {
    self->target();
}
