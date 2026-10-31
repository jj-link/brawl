#pragma force_active on

struct Entry {
    int pad;
    int value;
};

class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual Entry* v2(int i);
    virtual int v3();
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
    virtual unsigned v14();
};

class Main {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned v5();

    char pad[0x0C];
    Sub sub;
};

extern "C" int fn_27_2646BC(Main* self) {
    if (self->sub.v14() == 1)
        return 0x7FFF;

    if (self->v5() == 1)
        return 0;

    int idx = self->sub.v3() - 1;
    if (self->sub.v2(idx)->value < 0x7FFF) {
        int idx2 = self->sub.v3() - 1;
        return self->sub.v2(idx2)->value + 1;
    }

    int prev;
    int i = self->sub.v3() - 1;

    while (i >= 0) {
        if (i == 0) {
            if (self->sub.v2(i)->value == 0)
                return -1;
            return self->sub.v2(i)->value - 1;
        }

        prev = self->sub.v2(i - 1)->value;
        if (self->sub.v2(i)->value - 1 > prev)
            return self->sub.v2(i)->value - 1;

        i--;
    }

    return -1;
}
