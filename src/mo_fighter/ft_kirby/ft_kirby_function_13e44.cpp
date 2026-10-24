#pragma force_active on
struct KirbyGlobals {
    unsigned char firstChain[0xC];
    unsigned char firstObject[4];
    unsigned char secondChain[0xC];
    unsigned char secondObject[4];
    unsigned char thirdChain[0xC];
    unsigned char thirdObject[4];
    unsigned char fourthChain[0xC];
    unsigned char fourthObject[4];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern KirbyGlobals lbl_96_bss_C00;
void fn_96_13EE0(void**);
void* __register_global_object(void*, void* (*)(void*, short), void*);
void* fn_96_13E04(void*, short);
void* fn_96_13DC4(void*, short);
void* fn_96_13D84(void*, short);
void* fn_96_13D40(void*, short);
void fn_96_13EF0(void*);
void fn_96_13F00(void*);
void fn_96_13F10(void*);
void fn_96_13E44() {
    KirbyGlobals* base = &lbl_96_bss_C00;
    unsigned char (KirbyGlobals::*chain)[0xC] = &KirbyGlobals::firstChain;
    fn_96_13EE0(reinterpret_cast<void**>(base->firstObject));
    __register_global_object(base->firstObject, fn_96_13E04, &(base->*chain));
    fn_96_13EF0(base->secondObject);
    __register_global_object(base->secondObject, fn_96_13DC4, base->secondChain);
    fn_96_13F00(base->thirdObject);
    __register_global_object(base->thirdObject, fn_96_13D84, base->thirdChain);
    fn_96_13F10(base->fourthObject);
    __register_global_object(base->fourthObject, fn_96_13D40, base->fourthChain);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_96_13E44_ctor = (void*)fn_96_13E44;
