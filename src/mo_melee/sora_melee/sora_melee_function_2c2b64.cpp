#include <types.h>
#pragma force_active on

extern char lbl_27_data_7AC70[];

extern "C" {
void* getManager__11soArchiveDbFUl(u32);
void fn_80045E64(void*, void*);
void __dl__FPv(void*);
}

struct SoObj {
    void* m_00;
    void* m_04;
    u8 pad_08[0x8];
    const void* m_10;
};

extern "C" {
SoObj* fn_27_2C2B64(SoObj* self, s32 flags) {
    if (self) {
        self->m_10 = lbl_27_data_7AC70;
        fn_80045E64(getManager__11soArchiveDbFUl(2), self->m_04);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
