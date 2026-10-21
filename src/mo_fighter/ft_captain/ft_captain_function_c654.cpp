#pragma force_active on
struct CaptainGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x148];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern CaptainGlobals lbl_100_bss_8;
void* fn_100_C6B8(void*);
void* fn_100_9314(void*, short);
void* fn_100_C700(void*);
void* fn_100_C758(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void fn_100_C654() {
    CaptainGlobals* base = &lbl_100_bss_8;
    unsigned char (CaptainGlobals::*chain)[0xC] = &CaptainGlobals::firstChain;
    fn_100_C6B8(base->firstObject);
    __register_global_object(base->firstObject, fn_100_9314, &(base->*chain));
    fn_100_C700(base->secondObject);
    __register_global_object(base->secondObject, fn_100_C758, base->secondChain);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_100_C654_ctor = (void*)fn_100_C654;
