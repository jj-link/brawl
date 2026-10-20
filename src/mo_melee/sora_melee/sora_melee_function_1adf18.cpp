#pragma force_active on
struct Target {
    int m_pad;
    int m_value;
};

class Inner {
public:
    virtual void f0();
    virtual Target* get();
};

struct Outer {
    char m_pad[0x10];
    Inner m_inner;
};

extern "C" {
int fn_27_1ADF18(Outer* self) {
    Inner* p = &self->m_inner;
    return p->get()->m_value;
}
}
