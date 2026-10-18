#pragma force_active on
struct Target {
    char pad[0x18];
    unsigned int m_val;
};

struct Inner {
    virtual void f0();
    virtual Target* f1();
};

struct Outer {
    char pad[0x30];
    Inner* m_inner;
};

extern "C" {
void fn_27_3A664(Outer* self, int unused, unsigned int val) {
    Target* t = self->m_inner->f1();
    t->m_val = val;
}
}
