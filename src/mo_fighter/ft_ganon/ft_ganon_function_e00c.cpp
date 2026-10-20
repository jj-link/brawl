#pragma force_active on
struct Mod14 {
    virtual ~Mod14();
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void method(int a, int b);
};

struct Mod10Base {
    int a;
    int b;
};

struct Mod10 : public Mod10Base {
    virtual ~Mod10();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
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
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void method(int a, int b);
};

struct Accesser {
    void* _0;
    void* _4;
    void* _8;
    void* _c;
    Mod10* m_10;
    Mod14* m_14;
};

struct Fighter {
    char padding[0xd8];
    Accesser* accesser;
};

extern "C" char* lbl_27_bss_5668;

extern "C" void fn_109_E00C(Fighter* self) {
    char* p = lbl_27_bss_5668;
    if (p) {
        int v = *(int*)(p + 0x44);
        if (v == 0x2f) {
            self->accesser->m_14->method(2, 0);
            self->accesser->m_10->method(5, 0);
        }
    }
}
