#pragma force_active on
struct Pair {
    unsigned int a;
    unsigned int b;
};

struct Element {
    unsigned char a;
    unsigned int b;
    unsigned int c;
    unsigned char d;
    unsigned char e;
    Pair f;
};

class Object {
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
    virtual Element* at(int);
};

extern "C" void fn_27_ED1CC(Object* self, int from, int to) {
    Element* src = self->at(from);
    Element* dst = self->at(to);
    *dst = *src;
}
