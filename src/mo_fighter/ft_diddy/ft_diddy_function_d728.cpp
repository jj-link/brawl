#pragma force_active on
struct DiddyGlobals {
    unsigned char chain1[0xC];
    unsigned char obj1[0x1F0];
    unsigned char chain2[0xC];
    unsigned char obj2[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern DiddyGlobals lbl_115_bss_8;
void* fn_115_D78C(void*);
void* fn_115_D7D4(void*);
void* fn_115_9D60(void*, short);
void* fn_115_D82C(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);
void fn_115_D728() {
    DiddyGlobals* base = &lbl_115_bss_8;
    unsigned char (DiddyGlobals::*chain)[0xC] = &DiddyGlobals::chain1;
    fn_115_D78C(base->obj1);
    __register_global_object(base->obj1, fn_115_9D60, &(base->*chain));
    fn_115_D7D4(base->obj2);
    __register_global_object(base->obj2, fn_115_D82C, base->chain2);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_115_D728_ctor = (void*)fn_115_D728;
