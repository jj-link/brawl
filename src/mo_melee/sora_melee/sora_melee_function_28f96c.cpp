#pragma force_active on
class Sub {
public:
    virtual void f00(); virtual void f01(); virtual void f02(); virtual void f03(); virtual void f04();
    virtual void f05(); virtual void f06(); virtual void f07(); virtual void f08(); virtual void f09();
    virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
    virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24();
    virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28();
};

class Pad {
public:
    char m_pad[0x3c];
};

class Outer : public Pad {
public:
    virtual void g00(); virtual void g01(); virtual void g02(); virtual void g03(); virtual void g04();
    virtual void g05(); virtual void g06(); virtual void g07(); virtual void g08(); virtual void g09();
    virtual void g10(); virtual void g11(); virtual void g12(); virtual void g13(); virtual void g14();
    virtual void g15(); virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19();
    virtual void g20(); virtual void g21(); virtual void g22(); virtual void g23(); virtual void g24();
    virtual void g25(); virtual void g26(); virtual void g27(); virtual void g28(); virtual void g29();
    virtual void g30(); virtual void g31(); virtual void g32(); virtual void g33(); virtual void g34();
    virtual void g35(); virtual void g36(); virtual void g37(); virtual void g38(); virtual void g39();
    virtual void g40(); virtual void g41(); virtual void g42(); virtual void g43(); virtual void g44();
    virtual void g45();
    char m_pad2[0xdb4 - 0x40];
    Sub m_sub;
};

extern "C" void fn_27_28F96C(Outer* self) {
    self->m_sub.f26();
    self->g43();
}
