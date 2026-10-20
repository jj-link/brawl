#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

struct SoGlobalObj {
    u32 m_0;
    s32 m_4;
    u16 m_8;
    s16 m_a;
};

extern s8 lbl_27_bss_11D8;
extern SoGlobalObj lbl_27_bss_11DC;
extern u8 lbl_27_bss_E84[];

extern "C" void* fn_27_84358(void* p, s32 n);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern "C" void* fn_27_83784(void) {
    if (lbl_27_bss_11D8 == 0) {
        lbl_27_bss_11DC.m_4 = -1;
        lbl_27_bss_11DC.m_8 = 0;
        lbl_27_bss_11DC.m_a = -1;
        __register_global_object(&lbl_27_bss_11DC, (void*)fn_27_84358, lbl_27_bss_E84);
        lbl_27_bss_11D8 = 1;
    }
    return &lbl_27_bss_11DC;
}
