#pragma force_active on
struct Result {
    unsigned char padding[0x7c];
    float value;
};

struct Base {
    unsigned char padding[0x3c];

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
    virtual Result* getResult();
};

struct Object : Base {
    unsigned char padding1[0x1f4];
    float value;
    unsigned char padding2[4];
    unsigned char index;
    unsigned char state;
};

extern "C" bool fn_63_8BD0(Object* self, unsigned int index) {
    Result* result = self->getResult();
    if (result == 0) {
        return false;
    }
    if (self->state != 6) {
        return false;
    }
    if (self->index == index) {
        self->state = 7;
        self->value = result->value;
        return true;
    }
    return false;
}
