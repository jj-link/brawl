#include <gf/gf_callback.h>
#pragma force_active on
extern "C" {
void __register_global_object(void*, void*, void*);
void* fn_8005C5B0(void*, int);
extern int lbl_8042EBE0[];
extern int lbl_80497800[];
extern int lbl_805A0108[2];
extern int __vt__10gfCallBack[];
void fn_8005C574() {
    lbl_805A0108[1] = (int)__vt__10gfCallBack;
    lbl_805A0108[0] = 0;
    lbl_805A0108[1] = (int)lbl_8042EBE0;
    __register_global_object(lbl_805A0108, (void*)fn_8005C5B0, lbl_80497800);
}
}

__declspec(section ".ctors") extern void* const fn_8005C574_ctor = (void*)fn_8005C574;
