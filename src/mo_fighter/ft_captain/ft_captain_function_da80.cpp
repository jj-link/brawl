#pragma force_active on
struct CaptainGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[4];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern CaptainGlobals lbl_100_bss_198;
void* fn_100_DAE4(void*);
void* fn_100_DA40(void*, short);
void* fn_100_DAF4(void*);
void* fn_100_DA00(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_100_DA80() {
    CaptainGlobals* base = &lbl_100_bss_198;
    unsigned char (CaptainGlobals::*chain)[0xC] = &CaptainGlobals::firstChain;
    fn_100_DAE4(base->firstObject);
    __register_global_object(base->firstObject, fn_100_DA40, &(base->*chain));
    fn_100_DAF4(base->secondObject);
    __register_global_object(base->secondObject, fn_100_DA00, base->secondChain);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_100_DA80_ctor = (void*)fn_100_DA80;
