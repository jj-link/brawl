#pragma force_active on
extern "C" {
void fn_80106208(void* p);
void __dl__FPv(void* p);
}

struct SoObj {
    void* m_ptr;
};

extern "C" SoObj* fn_20_46F8(SoObj* self, int flag) {
    if (self) {
        if (self->m_ptr) {
            fn_80106208(self->m_ptr);
        }
        self->m_ptr = 0;
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
