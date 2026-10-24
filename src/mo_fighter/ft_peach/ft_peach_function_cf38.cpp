#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct PeachGlobals {
    unsigned char chain1[0xC];
    unsigned char obj1[0x160];
    unsigned char chain2[0xC];
    unsigned char obj2[0xC];
};

extern "C" {
extern PeachGlobals lbl_103_bss_8;
void* fn_103_CF9C(void*);
void* fn_103_CFE4(void*);
void* fn_103_9BC8(void*, short);
void* fn_103_D03C(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);

void fn_103_CF38() {
    PeachGlobals* base = &lbl_103_bss_8;
    unsigned char (PeachGlobals::*chain)[0xC] = &PeachGlobals::chain1;
    fn_103_CF9C(base->obj1);
    __register_global_object(base->obj1, fn_103_9BC8, &(base->*chain));
    fn_103_CFE4(base->obj2);
    __register_global_object(base->obj2, fn_103_D03C, base->chain2);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_103_CF38_ctor = (void*)fn_103_CF38;
