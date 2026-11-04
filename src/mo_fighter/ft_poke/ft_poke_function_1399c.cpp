#pragma force_active on
typedef unsigned char u8;

struct Argument {
    virtual void unused();
    virtual signed char getKind();
    virtual signed char getIndex();
};

struct Object {
    u8 reserved[0x3C];
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

struct Module {
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
    virtual void setFlag(int, void*);
};

extern "C" int fn_27_1DA24C(Object*, Argument*);

extern "C" int fn_116_1399C(Object* self, Argument* argument) {
    if (fn_27_1DA24C(self, argument)) {
        return 1;
    }
    if (!self->acceptKind(argument->getKind())) {
        return 0;
    }
    if (argument->getIndex() <= -1 || argument->getIndex() >= 11) {
        return 0;
    }
    switch (argument->getIndex()) {
    case 6: {
        u8* m = *(u8**)((u8*)self + 0x60);
        Module* obj = *(Module**)(*(u8**)(m + 0xD8) + 0x70);
        obj->setFlag(1, m);
        return 1;
    }
    }
    return 0;
}
