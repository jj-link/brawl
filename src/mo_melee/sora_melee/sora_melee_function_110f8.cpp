#pragma force_active on
struct ObjectBase {
    unsigned char padding0[8];

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
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual unsigned int first();
    virtual unsigned int second();
};

struct Object : ObjectBase {
    unsigned char padding1[0x20];
    int active;
    unsigned char padding2[0x14];
    unsigned char flags : 1;
    unsigned char otherFlags : 7;
};

extern "C" bool fn_27_110F8(Object* self, unsigned int mode) {
    if (self->active != 0 && !self->flags &&
        ((mode == 0 && self->first() == 1) ||
         (mode == 1 && self->second() == 1))) {
        return true;
    }
    return false;
}
