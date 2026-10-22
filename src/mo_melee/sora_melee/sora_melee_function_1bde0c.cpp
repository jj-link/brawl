#pragma force_active on

struct Element {
    int pad;
    int value;
};

class Array {
public:
    virtual void a0();
    virtual void a1();
    virtual Element* a2(int index);
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
    virtual unsigned a14();
};

class MainObj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual unsigned m5();
    char pad[12];
    Array m_array;
};

extern "C" int fn_27_1BDE0C(MainObj* self) {
    if (self->m_array.a14() == 1) {
        return 0x7FFF;
    }
    if (self->m5() == 1) {
        return 0;
    }
    
    int n = self->m_array.a3() - 1;
    if (self->m_array.a2(n)->value < 0x7FFF) {
        n = self->m_array.a3() - 1;
        return self->m_array.a2(n)->value + 1;
    }
    
    int prev_val;
    int i = self->m_array.a3() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_array.a2(i)->value == 0) {
                return -1;
            }
            return self->m_array.a2(i)->value - 1;
        }
        prev_val = self->m_array.a2(i - 1)->value;
        if (self->m_array.a2(i)->value - 1 > prev_val) {
            return self->m_array.a2(i)->value - 1;
        }
        i--;
    }
    return -1;
}
