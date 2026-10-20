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
    virtual short operation(unsigned int*, int, unsigned short*, signed char);
};

struct Object {
    unsigned char padding[8];
    Target* target;
};

extern "C" int fn_27_DA734(Object* object, unsigned int value, signed char index) {
    unsigned short result = 0;
    return object->target->operation(&value, -1, &result, index);
}
