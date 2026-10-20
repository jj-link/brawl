#include <types.h>
#pragma force_active on

extern "C" {
extern s8 lbl_27_bss_1118;
extern u8 lbl_27_bss_E24[];
extern void* fn_27_84198(void* p, s32 n);
void* __register_global_object(void* object, void* destructor, void* chain);
}

struct SoGlobal111C {
    s32 m_unk0;
    s32 m_a;
    s16 m_b;
    s16 m_c;
};

extern "C" {
extern SoGlobal111C lbl_27_bss_111C;
}

extern "C" SoGlobal111C* fn_27_830A4() {
    if (lbl_27_bss_1118 == 0) {
        lbl_27_bss_111C.m_a = -1;
        lbl_27_bss_111C.m_b = 0;
        lbl_27_bss_111C.m_c = -1;
        __register_global_object(&lbl_27_bss_111C, (void*)fn_27_84198, lbl_27_bss_E24);
        lbl_27_bss_1118 = 1;
    }
    return &lbl_27_bss_111C;
}
