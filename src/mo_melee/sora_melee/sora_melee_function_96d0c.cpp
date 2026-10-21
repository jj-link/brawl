#pragma force_active on
class Target {
public:
    virtual int slot0();
    virtual int slot1();
    virtual int slot2();
    virtual int slot3();
    virtual int slot4();
    virtual int slot5();
    virtual int slot6();
    virtual int slot7();
    virtual int slot8();
    virtual int method();
};

struct Object {
    unsigned char padding[0x30];
    Target* target;
};

extern "C" int fn_27_96D0C(Object* self) {
    return self->target->method();
}
