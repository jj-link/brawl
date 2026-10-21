#pragma force_active on
extern "C" {
void __dla__FPv(void*);
void __dl__FPv(void*);
}

struct fn_27_Inner {
    virtual void destroy(bool);
};

struct fn_27_Outer {
    fn_27_Inner* m_inner;
    void* m_arr;
};

extern "C" fn_27_Outer* fn_27_227EF0(fn_27_Outer* self, int del) {
    if (self != 0) {
        if (self->m_inner != 0 && self->m_inner != 0) {
            self->m_inner->destroy(true);
        }
        self->m_inner = 0;
        if (self->m_arr != 0 && self->m_arr != 0) {
            __dla__FPv((char*)self->m_arr - 0x10);
        }
        self->m_arr = 0;
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
