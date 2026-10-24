#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct SonicGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x2A0];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};

extern "C" {
extern SonicGlobals lbl_123_bss_8;
void* fn_123_EDA4(void*);
void* fn_123_9E8C(void*, short);
void* fn_123_EDEC(void*);
void* fn_123_EE44(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);
void fn_123_ED40() {
    SonicGlobals* base = &lbl_123_bss_8;
    unsigned char (SonicGlobals::*chain)[0xC] = &SonicGlobals::firstChain;
    fn_123_EDA4(base->firstObject);
    __register_global_object(base->firstObject, fn_123_9E8C, &(base->*chain));
    fn_123_EDEC(base->secondObject);
    __register_global_object(base->secondObject, fn_123_EE44, base->secondChain);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_123_ED40_ctor = (void*)fn_123_ED40;
