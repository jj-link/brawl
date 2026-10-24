#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct GanonGlobals2 {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0x4];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0x4];
    unsigned char thirdChain[0xC];
    unsigned char thirdObject[0x4];
};

extern "C" {
extern GanonGlobals2 lbl_109_bss_1C8;

void fn_109_E1D0(void**);
void fn_109_E1E0(unsigned char**);
void* fn_109_E1F0(void*);
void* fn_109_E110(void*, short);
void* fn_109_E0D0(void*, short);
void* fn_109_E090(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
}

extern "C" void fn_109_E150() {
    GanonGlobals2* base = &lbl_109_bss_1C8;
    unsigned char (GanonGlobals2::*chain)[0xC] = &GanonGlobals2::firstChain;

    fn_109_E1D0(reinterpret_cast<void**>(base->firstObject));
    __register_global_object(base->firstObject, fn_109_E110, &(base->*chain));

    fn_109_E1E0(reinterpret_cast<unsigned char**>(base->secondObject));
    __register_global_object(base->secondObject, fn_109_E0D0, base->secondChain);

    fn_109_E1F0(base->thirdObject);
    __register_global_object(base->thirdObject, fn_109_E090, base->thirdChain);
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_109_E150_ctor = (void*)fn_109_E150;
