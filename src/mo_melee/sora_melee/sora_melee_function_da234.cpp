#pragma force_active on
struct Object {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual int call(unsigned int*, int, short*, int);
};

struct Wrapper {
    unsigned int padding[2];
    Object* object;
};

extern "C" int fn_27_DA234(Wrapper* self, unsigned int value, signed char flag) {
    short result = 0;
    return (short)self->object->call(&value, -1, &result, flag);
}
