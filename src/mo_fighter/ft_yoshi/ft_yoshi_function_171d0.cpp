#pragma force_active on
struct Argument {
    virtual void unused();
    virtual signed char getKind();
    virtual signed char getIndex();
};

struct Object {
    unsigned char reserved[0x3C];

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
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual int acceptKind(signed char);
};

extern "C" int fn_27_1DA24C(Object*, Argument*);

extern "C" int fn_95_171D0(Object* self, Argument* argument) {
    if (fn_27_1DA24C(self, argument)) {
        return 1;
    }
    if (!self->acceptKind(argument->getKind())) {
        return 0;
    }
    if (argument->getIndex() > -1) {
        argument->getIndex();
    }
    return 0;
}
