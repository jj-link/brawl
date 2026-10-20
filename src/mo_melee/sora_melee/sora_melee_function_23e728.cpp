#pragma force_active on
struct Data {
    unsigned char kind;
};

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
    virtual Data* getData();

    unsigned char padding1[0x15];
    unsigned char flag;
};

extern "C" bool fn_27_23E728(Object* self) {
    Data* data = self->getData();
    if (!data) {
        return false;
    }
    if (data->kind == 0x0C || data->kind == 0x17) {
        self->flag = 0;
        return true;
    }
    return false;
}
