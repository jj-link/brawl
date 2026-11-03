#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern "C" float fn_27_192278(void*, unsigned long);

struct P {
    float x;
    float y;
};

inline P copyP(P p) {
    return p;
}

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual P fn_27_14D08(short*);
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00();
    virtual void fn_27_14B80();
    virtual void fn_27_14B88();
    virtual void fn_27_16A70();
    virtual void fn_27_16AB8();
    virtual void fn_27_1CBB4();
    virtual void fn_27_14A20();
    virtual void fn_27_1CBAC();
    virtual void fn_27_1CBA4();
    virtual void fn_27_14B98();
    virtual void fn_27_14B90();
    virtual void fn_27_1CB88();
    virtual void fn_27_14CF8();
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(int, int);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual int slot14(int, int);
    virtual void slot15();
    virtual void slot16();
    virtual void slot17(int, int, int);
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual int slot27(int);
};

struct Inner {
    char pad[0x1c];
    soNullable* m1c;
    char pad2[0x5c];
    Class_1250* m7c;
};

struct Obj {
    char pad[0xd8];
    Inner* in;
};

extern "C" void fn_27_3C73F8(Obj* self) {
    short s = 1;
    P q = copyP(self->in->m7c->fn_27_14D08(&s));
    float a = nw4r::ut::Abs(q.x);
    int ok;

    if (a < fn_27_192278(self, 0xfc2)) {
        self->in->m1c->slot5(0);
        ok = 0;
    } else {
        soNullable* m = self->in->m1c;
        m->slot8(0, m->slot27(0));
        ok = 1;
    }

    if (ok) {
        float f = fn_27_192278(self, 0xfb1);
        float g = fn_27_192278(self, 0xfb0);
        float t = a + g;
        t *= f;
        int n = (int)t;
        if (n < 1)
            n = 1;
        if (self->in->m1c->slot14(0, 0)) {
            self->in->m1c->slot17(0, n, 0);
        }
    }
}
