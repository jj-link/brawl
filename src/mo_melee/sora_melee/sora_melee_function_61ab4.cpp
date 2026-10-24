#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_8B0;

struct Elem {
    char pad[0xC];
    float m_f;
};

class Arr {
public:
    virtual void f0();
    virtual Elem* at(int);
    virtual void f2();
    virtual int size();
};

struct Base {
    char pad[8];
};

class Owner : public Base {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual int check(Elem*);

    char pad2[0x34];
    Arr* arr;
};

extern "C" int fn_27_61AB4(Owner* self) {
    for (int i = 0; i < self->arr->size(); i++) {
        Elem* e = self->arr->at(i);
        if (e->m_f >= lbl_27_rodata_8B0) {
            if (self->check(e) == 0)
                return 1;
        }
    }
    return 0;
}
