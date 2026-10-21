#pragma force_active on

class Target {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void invoke(void*, int);
};

struct Object {
    void* values[5];
    char padding[0x10];
    unsigned char high : 2;
    unsigned char disabled : 1;
    unsigned char low : 5;
};

extern "C" void fn_27_1FE18(Object* self, Target* target) {
    if (!self->disabled) {
        if (self->values[0]) target->invoke(self->values[0], 6);
        if (self->values[1]) target->invoke(self->values[1], 6);
        if (self->values[2]) target->invoke(self->values[2], 6);
        if (self->values[3]) target->invoke(self->values[3], 6);
        if (self->values[4]) target->invoke(self->values[4], 6);
    }
}
