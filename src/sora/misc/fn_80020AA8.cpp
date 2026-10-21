#include <types.h>
#pragma force_active on

extern "C" {
void OSInitMutex(void* mutex);
void __register_global_object(void* obj, void (*dtor)(void*), void* ctx);
extern char fn_80020AF8[];
extern char lbl_80494900[];
extern char lbl_80494910[];
extern s32 lbl_8059FFEC;
}

extern "C" void fn_80020AA8() {
    OSInitMutex(lbl_80494910);
    __register_global_object(lbl_80494910, (void (*)(void*))fn_80020AF8, lbl_80494900);
    lbl_8059FFEC = 0;
}

__declspec(section ".ctors") extern void* const fn_80020AA8_ctor = (void*)fn_80020AA8;
