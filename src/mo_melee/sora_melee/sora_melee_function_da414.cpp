#pragma force_active on
struct Target {
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
    virtual int call(int*, int, short*, signed char);
};

struct Object {
    char padding[8];
    Target* target;
};

extern "C" short fn_27_DA414(Object* self, int value, signed char arg) {
    short result = 0;
    return self->target->call(&value, -1, &result, arg);
}
