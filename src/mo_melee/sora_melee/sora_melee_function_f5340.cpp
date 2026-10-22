#pragma force_active on

struct Elem {
    int pad;
    int val;
};

class Sub {
public:
    virtual void s2();
    virtual void s3();
    virtual Elem* s4(int idx);
    virtual int s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual unsigned int s16();
};

class Owner {
public:
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
    virtual unsigned int o7();
    char pad[0xC];
    Sub sub;
};

extern "C" int fn_27_F5340(Owner* self) {
    int prev;
    int i;
    int idx;

    if (self->sub.s16() == 1U) {
        return 0x7FFF;
    }
    if (self->o7() == 1U) {
        return 0;
    }
    idx = self->sub.s5() - 1;
    if (self->sub.s4(idx)->val < 0x7FFF) {
        idx = self->sub.s5() - 1;
        return self->sub.s4(idx)->val + 1;
    }
    i = self->sub.s5() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->sub.s4(i)->val == 0) {
                return -1;
            }
            return self->sub.s4(i)->val - 1;
        }
        prev = self->sub.s4(i - 1)->val;
        if (self->sub.s4(i)->val - 1 > prev) {
            return self->sub.s4(i)->val - 1;
        }
        i--;
    }
    return -1;
}
