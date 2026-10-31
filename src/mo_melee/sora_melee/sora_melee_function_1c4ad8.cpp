#pragma force_active on

struct Item {
    int _0;
    int _4;
};

class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual Item* f2(int index);
    virtual int f3();
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
    virtual int f14();
};

class Main {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int f5();

    unsigned char pad[12];
    Sub sub;
};

extern "C" int fn_27_1C4AD8(Main* self) {
    if ((unsigned) self->sub.f14() == 1U)
        return 0x7fff;

    if ((unsigned) self->f5() == 1U)
        return 0;

    int idx = self->sub.f3() - 1;
    if (self->sub.f2(idx)->_4 < 0x7fff) {
        idx = self->sub.f3() - 1;
        return self->sub.f2(idx)->_4 + 1;
    }

    int i = self->sub.f3() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->sub.f2(i)->_4 == 0)
                return -1;
            return self->sub.f2(i)->_4 - 1;
        }

        if (self->sub.f2(i)->_4 - 1 > self->sub.f2(i - 1)->_4)
            return self->sub.f2(i)->_4 - 1;

        i--;
    }

    return -1;
}
