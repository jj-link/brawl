#pragma force_active on

struct Item {
    int pad;
    int value;
};

class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual Item* get(int index);
    virtual int size();
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
    virtual unsigned full();
};

class Arg0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual unsigned check();
    char pad[0xC];
    Sub sub;
};

extern "C" int fn_27_1C99F8(Arg0* self) {
    if (self->sub.full() == 1) {
        return 0x7FFF;
    }
    if (self->check() == 1) {
        return 0;
    }

    int index = self->sub.size() - 1;
    if (self->sub.get(index)->value < 0x7FFF) {
        index = self->sub.size() - 1;
        return self->sub.get(index)->value + 1;
    }

    int previous;
    int i = self->sub.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->sub.get(i)->value == 0) {
                return -1;
            }
            return self->sub.get(i)->value - 1;
        }
        previous = self->sub.get(i - 1)->value;
        if (self->sub.get(i)->value - 1 > previous) {
            return self->sub.get(i)->value - 1;
        }
        --i;
    }
    return -1;
}
