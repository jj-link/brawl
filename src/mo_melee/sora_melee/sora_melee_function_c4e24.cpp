#pragma force_active on
struct SubRes {
    int pad0;
    int m_value;
};

class SubObj {
public:
    virtual void f0();
    virtual SubRes* f1();
};

class Outer {
public:
    int m_pad0;
    int m_pad1;
    int m_pad2;
    int m_pad3;
    SubObj m_sub;
};

extern "C" int fn_27_C4E24(Outer* self) {
    return self->m_sub.f1()->m_value;
}
