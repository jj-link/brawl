#pragma force_active on
struct Pair {
    int a;
    int b;
};

struct Value {
    Pair pair;
    int c;
    short d;
    short e;
};

struct Object {
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
    virtual Value* at(int);
};

extern "C" void fn_27_DE00C(Object* self, int from, int to) {
    Value* src = self->at(from);
    Value* dst = self->at(to);
    *dst = *src;
}
