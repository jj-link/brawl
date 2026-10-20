#include <types.h>
#pragma force_active on

struct stFoo {
    void* m_vtbl;
    u8 pad[0x4C - 4];
    void* m_dataTable;
};

extern "C" {
extern u8 lbl_27_data_27478[];
void fn_27_118F50();
void fn_803F0D4C(void* block, void (*destroy)());
void __dl__FPv(void* p);
extern void* g_ftEntryManager;
}

extern "C" stFoo* fn_27_119054(stFoo* self, s32 flags) {
    if (self) {
        self->m_dataTable = lbl_27_data_27478;
        fn_803F0D4C(self->m_vtbl, fn_27_118F50);
        self->m_vtbl = 0;
        g_ftEntryManager = 0;
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
