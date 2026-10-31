#pragma force_active on

class Element {
public:
    int pad0;
    int value;
};

class Arr {
public:
    virtual void a0();
    virtual void a1();
    virtual Element* a2(int idx);
    virtual int a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual unsigned int a14();
};

class Outer {
public:
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual unsigned int o5();
    int pad[3];
    Arr arr;
};

extern "C" int fn_27_FB628(Outer* self) {
    if (self->arr.a14() == 1U) {
        return 0x7FFF;
    }
    if (self->o5() == 1U) {
        return 0;
    }

    int idx = self->arr.a3() - 1;
    if (self->arr.a2(idx)->value < 0x7FFF) {
        idx = self->arr.a3() - 1;
        return self->arr.a2(idx)->value + 1;
    }

    int prev_val;
    int i = self->arr.a3() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->arr.a2(i)->value == 0) {
                return -1;
            }
            return self->arr.a2(i)->value - 1;
        }
        prev_val = self->arr.a2(i - 1)->value;
        if (self->arr.a2(i)->value - 1 > prev_val) {
            return self->arr.a2(i)->value - 1;
        }
        i--;
    }
    return -1;
}
