#pragma force_active on
struct Base {
    unsigned char padding[0x3C];

    virtual int unused0();
    virtual int unused1();
    virtual int unused2();
    virtual int unused3();
    virtual int unused4();
    virtual int unused5();
    virtual int unused6();
    virtual int unused7();
    virtual int unused8();
    virtual int unused9();
    virtual int unused10();
    virtual int unused11();
    virtual int unused12();
    virtual int unused13();
    virtual int unused14();
    virtual int unused15();
    virtual int unused16();
    virtual int unused17();
    virtual int unused18();
    virtual int unused19();
    virtual int unused20();
    virtual int unused21();
    virtual int unused22();
    virtual int unused23();
    virtual int unused24();
    virtual int unused25();
    virtual int unused26();
    virtual int unused27();
    virtual int unused28();
    virtual int unused29();
    virtual int unused30();
    virtual int unused31();
    virtual int unused32();
    virtual int unused33();
    virtual int unused34();
    virtual int unused35();
    virtual int unused36();
    virtual int test();
};

struct Object : Base {
    unsigned char padding40[4];
    unsigned char state;
};

extern "C" bool fn_27_23E798(Object* self) {
    if (self->test() == 0)
        return false;
    if (self->state == 0)
        return false;
    if (self->state == 3)
        return false;
    return self->state != 6;
}
