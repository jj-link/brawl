#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct GanonGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x4];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0x4];
};

extern "C" {
extern GanonGlobals lbl_109_bss_2C0;
void fn_109_11F4C(void**);
void fn_109_11F5C(void**);
void* fn_109_11EA8(void*, short);
void* fn_109_11E68(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);

void fn_109_11EE8() {
    GanonGlobals* base = &lbl_109_bss_2C0;
    unsigned char (GanonGlobals::*chain)[0xC] = &GanonGlobals::firstChain;
    fn_109_11F4C(reinterpret_cast<void**>(base->firstObject));
    __register_global_object(base->firstObject, fn_109_11EA8, &(base->*chain));
    fn_109_11F5C(reinterpret_cast<void**>(base->secondObject));
    __register_global_object(base->secondObject, fn_109_11E68, base->secondChain);
}
}

#pragma pop

extern void* const fn_109_11EE8_ctor;

__declspec(section ".ctors") extern void* const fn_109_11EE8_ctor = (void*)fn_109_11EE8;
