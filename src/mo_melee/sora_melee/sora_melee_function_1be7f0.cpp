#pragma force_active on

class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual int* get(int);
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
    virtual unsigned f14();
};

class Main {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual unsigned m5();
    char pad[12];
    Sub sub;
};

extern "C" int fn_27_1BE7F0(Main* self) {
    if (self->sub.f14() == 1) {
        return 0x7FFF;
    }
    if (self->m5() == 1) {
        return 0;
    }
    int idx = self->sub.size() - 1;
    if (*(self->sub.get(idx) + 1) < 0x7FFF) {
        idx = self->sub.size() - 1;
        return *(self->sub.get(idx) + 1) + 1;
    }
    int i = self->sub.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (*(self->sub.get(i) + 1) == 0) {
                return -1;
            }
            return *(self->sub.get(i) + 1) - 1;
        }
        if (*(self->sub.get(i) + 1) - 1 > *(self->sub.get(i - 1) + 1)) {
            return *(self->sub.get(i) + 1) - 1;
        }
        i--;
    }
    return -1;
}
