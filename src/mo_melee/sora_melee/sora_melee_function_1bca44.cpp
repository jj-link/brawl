#pragma force_active on

struct Entry {
    int first;
    int value;
};

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual Entry& get(unsigned int index);
    virtual unsigned v3();
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
    virtual unsigned full();
};

class Outer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned check();

    char pad[12];
    Inner inner;
};

extern "C" int fn_27_1BCA44(Outer* self) {
    if (self->inner.full() == 1)
        return 0x7FFF;

    if (self->check() == 1)
        return 0;

    int index = self->inner.v3() - 1;
    if (self->inner.get(index).value < 0x7FFF) {
        index = self->inner.v3() - 1;
        return self->inner.get(index).value + 1;
    }

    int saved;
    int i = self->inner.v3() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->inner.get(i).value == 0)
                return -1;
            return self->inner.get(i).value - 1;
        }

        saved = self->inner.get(i - 1).value;
        if (self->inner.get(i).value - 1 > saved)
            return self->inner.get(i).value - 1;

        i--;
    }

    return -1;
}
