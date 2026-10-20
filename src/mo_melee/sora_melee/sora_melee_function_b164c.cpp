#pragma force_active on
extern "C" void fn_8009EE60(void*, int);
extern "C" void __dl__FPv(void*);
extern char lbl_27_data_16D08[];

struct fn_27_B164C_Obj {
    int pad0;
    void* m_4;
    char pad8[0x40 - 0x8];
    void* m_40;
};

extern "C" {
fn_27_B164C_Obj* fn_27_B164C(fn_27_B164C_Obj* self, int flag) {
    if (self) {
        void* p = self->m_4;
        self->m_40 = lbl_27_data_16D08;
        if (p != 0) {
            fn_8009EE60(p, 1);
            self->m_4 = 0;
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
