#pragma force_active on
struct SamusGlobals {
    unsigned char chain1[0xC];
    unsigned char obj1[4];
    unsigned char chain2[0xC];
    unsigned char obj2[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern SamusGlobals lbl_94_bss_1D0;
void* fn_94_10858(void*);
void* fn_94_107B4(void*, short);
void fn_94_10868(void*);
void* fn_94_10774(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_94_107F4() {
    SamusGlobals* base = &lbl_94_bss_1D0;
    unsigned char (SamusGlobals::*chain)[0xC] = &SamusGlobals::chain1;
    fn_94_10858(base->obj1);
    __register_global_object(base->obj1, fn_94_107B4, &(base->*chain));
    fn_94_10868(base->obj2);
    __register_global_object(base->obj2, fn_94_10774, base->chain2);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_94_107F4_ctor = (void*)fn_94_107F4;
