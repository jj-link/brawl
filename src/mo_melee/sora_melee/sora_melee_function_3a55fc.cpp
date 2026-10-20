#include <types.h>
#pragma force_active on

extern "C" void fn_27_1E847C(void* self, int id, void* data);
extern "C" void __dl__FPv(void* p);

extern char lbl_27_data_9D048[];
extern char lbl_27_bss_54EC[];

struct stMeleeDerived {
    void* m_vt0;
    u32 m_pad4;
    void* m_vt1;
};

extern "C" {
stMeleeDerived* fn_27_3A55FC(stMeleeDerived* self, int flag) {
    if (self) {
        self->m_vt0 = lbl_27_data_9D048 + 8;
        self->m_vt1 = lbl_27_data_9D048;
        fn_27_1E847C(self, 0x2e, lbl_27_bss_54EC);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
