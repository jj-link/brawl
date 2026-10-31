#pragma force_active on

struct Element {
    int pad;
    int value;
};

class Vector {
public:
    virtual void v0();
    virtual void v1();
    virtual Element* get(int index);
    virtual int size();
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
    virtual unsigned int v14();
};

class Owner {
public:
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual unsigned int check();
    char pad[12];
    Vector vec;
};

extern "C" int fn_27_1E79D8(Owner* self) {
    if (self->vec.v14() == 1)
        return 0x7FFF;
    if (self->check() == 1)
        return 0;

    int idx = self->vec.size() - 1;
    if (self->vec.get(idx)->value < 0x7FFF) {
        idx = self->vec.size() - 1;
        return self->vec.get(idx)->value + 1;
    }

    int prev;
    int i = self->vec.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->vec.get(i)->value == 0)
                return -1;
            return self->vec.get(i)->value - 1;
        }
        prev = self->vec.get(i - 1)->value;
        if (self->vec.get(i)->value - 1 > prev)
            return self->vec.get(i)->value - 1;
        i--;
    }
    return -1;
}
