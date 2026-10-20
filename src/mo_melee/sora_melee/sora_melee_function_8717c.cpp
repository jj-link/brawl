#pragma force_active on
class Target {
public:
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
    virtual void call(const int*, int, const short*, int);
};

struct Context {
    char padding[0x14];
    Target* target;
};

extern "C" void fn_27_8717C(Context* self, int value, int arg,
                           const short* input, int count) {
    short copy = *input;
    self->target->call(&value, arg, &copy, (short)count);
}
