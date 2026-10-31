#pragma force_active on
struct DonkeyGlobals {
    unsigned char chain1[0xC];
    unsigned char obj1[0x160];
    unsigned char chain2[0xC];
    unsigned char obj2[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern DonkeyGlobals lbl_92_bss_8;
void* fn_92_C8E0(void*);
void* fn_92_9480(void*, short);
void* fn_92_C928(void*);
void* fn_92_C980(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);
void fn_92_C87C() {
    DonkeyGlobals* base = &lbl_92_bss_8;
    unsigned char (DonkeyGlobals::*chain)[0xC] = &DonkeyGlobals::chain1;
    fn_92_C8E0(base->obj1);
    __register_global_object(base->obj1, fn_92_9480, &(base->*chain));
    fn_92_C928(base->obj2);
    __register_global_object(base->obj2, fn_92_C980, base->chain2);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_92_C87C_ctor = (void*)fn_92_C87C;
