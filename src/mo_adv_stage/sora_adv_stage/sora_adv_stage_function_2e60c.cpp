#pragma force_active on
typedef unsigned int u32;

struct Src {
    u32 val;
};

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v5(const Src* s);
    u32 m_val;
};

extern "C" {
void fn_40_2E60C(Obj* self, const Src* s) {
    self->m_val = s->val;
    self->v5(s);
}
}
