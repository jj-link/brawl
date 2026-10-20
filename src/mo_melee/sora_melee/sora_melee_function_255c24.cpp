#pragma force_active on
extern "C" int fn_27_23AC10(void*);

class Object {
    char padding[0x3C];

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
    virtual void invoke();
};

struct Container {
    char padding[0x48];
    Object* objects[7];
};

extern "C" void fn_27_255C24(Container* self) {
    for (int i = 0; i < 7; ++i) {
        if (self->objects[i] && fn_27_23AC10(self->objects[i])) {
            self->objects[i]->invoke();
        }
    }
}
