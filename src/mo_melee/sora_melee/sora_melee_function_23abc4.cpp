#pragma force_active on
struct Base {
    unsigned char padding[0x3C];
};

struct Object : Base {
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
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual int getState();

    unsigned char padding1[4];
    unsigned char state;
};

extern "C" bool fn_27_23ABC4(Object* self) {
    if (self->state == 6) {
        return true;
    }
    return self->getState() == 1;
}
