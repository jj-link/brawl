#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct KirbyGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[0xBA8];
    unsigned char secondChain[0xC];
    unsigned char secondObject[0xC];
};

extern "C" {
extern KirbyGlobals lbl_96_bss_8;
void* fn_96_13380(void*);
void* fn_96_EF14(void*, short);
void* fn_96_133C8(void*);
void* fn_96_13420(void*, short);
void* __register_global_object(void*, void*, void*);
void fn_96_1331C() {
    KirbyGlobals* base = &lbl_96_bss_8;
    unsigned char (KirbyGlobals::*chain)[0xC] = &KirbyGlobals::firstChain;

    fn_96_13380(base->firstObject);
    __register_global_object(base->firstObject, reinterpret_cast<void*>(fn_96_EF14), &(base->*chain));
    fn_96_133C8(base->secondObject);
    __register_global_object(base->secondObject, reinterpret_cast<void*>(fn_96_13420), base->secondChain);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_96_1331C_ctor = (void*)fn_96_1331C;
