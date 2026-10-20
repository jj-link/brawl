#pragma force_active on
extern "C" const float lbl_27_rodata_279C;

class Work {
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
    virtual float getFloat(unsigned int);
};

struct Modules {
    char padding[0x64];
    Work* work;
};

struct Owner {
    char padding[0xD8];
    Modules* modules;
};

struct ObjectPrefix {
    char padding[0x3C];
};

class ObjectInterface : public ObjectPrefix {
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
    virtual int query();
};

class Object : public ObjectInterface {
public:
    char padding[0x20];
    Owner* owner;
};

extern "C" float fn_27_1DB674(Object* self) {
    if (self->query() == 0) {
        return lbl_27_rodata_279C;
    }
    return self->owner->modules->work->getFloat(0x11000000);
}
