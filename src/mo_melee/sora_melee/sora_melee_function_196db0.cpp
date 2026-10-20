#pragma force_active on
class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

class Owner {
public:
    virtual void base();
    Sub* m_sub;
    int m_pad8;
    int m_count;
};

extern "C" void fn_27_196DB0(Owner* self) {
    if (self->m_sub != 0) {
        if (self->m_sub->v4() == 0) {
            self->m_sub->v7();
            return;
        }
    }
    if (self->m_count > 0) {
        self->m_count--;
    }
}
