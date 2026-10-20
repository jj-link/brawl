#pragma force_active on
class Inner {
public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
};

class Outer {
public:
    int pad[4];
    Inner m_inner;
};

extern "C" {
int fn_27_F6C64(Outer* self) {
    Inner* p = &self->m_inner;
    return p->f1();
}
}
