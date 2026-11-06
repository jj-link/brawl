#pragma force_active on

class ABase {
public:
    unsigned int m_0;
    unsigned int m_4;
};

class FooA : public ABase {
public:
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
    virtual void* f14(int);
};

class BBase {
public:
    unsigned int m_0;
    unsigned int m_4;
};

class FooB : public BBase {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g20();
    virtual void g21();
    virtual void g22();
    virtual void g23();
    virtual void g24();
    virtual void g25();
    virtual void g26();
    virtual void g27();
    virtual void g28();
    virtual void g29();
    virtual void g30();
    virtual void g31();
    virtual void g32();
    virtual void g33();
    virtual void g34();
    virtual void g35();
    virtual void g36();
    virtual void g37();
    virtual void g38();
    virtual int g39(void*);
};

struct BaseItemLike {
    unsigned char pad[0x8d0];
    FooB* m_8d0;
    unsigned char pad2[0x130];
    FooA m_a04;
};

extern "C" void fn_801AB014(void*, int);
extern "C" void fn_801AAFF0(void*, int);

extern "C" void fn_27_28E7B4(BaseItemLike* self, int v) {
    void* res = self->m_a04.f14(0);
    if (res != 0) {
        int r2 = self->m_8d0->g39(self);
        if (r2 >= 3) {
            fn_801AB014(res, v);
            fn_801AAFF0(res, v);
        } else {
            fn_801AAFF0(res, v);
        }
    }
}
