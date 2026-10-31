#pragma force_active on

class Element {
public:
    char pad[8];
    int value;
};

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual Element* get(unsigned int index);
    virtual unsigned int size();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual unsigned int check();
};

class Outer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int check2();

    char pad[12];
    Inner inner;
};

extern "C" int fn_27_3198D0(Outer* self) {
    if (self->inner.check() == 1U) {
        return 0x7fff;
    }
    if (self->check2() == 1U) {
        return 0;
    }

    int index = self->inner.size() - 1;
    if (self->inner.get(index)->value < 0x7fff) {
        index = self->inner.size() - 1;
        return self->inner.get(index)->value + 1;
    }

    int i = self->inner.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->inner.get(i)->value == 0) {
                return -1;
            }
            return self->inner.get(i)->value - 1;
        }

        if (self->inner.get(i)->value - 1 >
            self->inner.get(i - 1)->value) {
            return self->inner.get(i)->value - 1;
        }
        --i;
    }

    return -1;
}
