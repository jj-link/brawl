#pragma force_active on
struct ToonLinkGlobals {
    unsigned char reg1[0xC];
    unsigned char obj1[0xE8];
    unsigned char reg2[0xC];
    unsigned char obj2[0xC];
};

#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern ToonLinkGlobals lbl_121_bss_8;
void* fn_121_E9B8(void*);
void* fn_121_AD30(void*, short);
void* fn_121_EA00(void*);
void* fn_121_EA58(void*, short);
void* __register_global_object(void*, void*, void*);

void fn_121_E954() {
    ToonLinkGlobals* base = &lbl_121_bss_8;
    unsigned char (ToonLinkGlobals::*reg)[0xC] = &ToonLinkGlobals::reg1;

    fn_121_E9B8(base->obj1);
    __register_global_object(base->obj1, fn_121_AD30, &(base->*reg));

    fn_121_EA00(base->obj2);
    __register_global_object(base->obj2, fn_121_EA58, base->reg2);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_121_E954_ctor = (void*)fn_121_E954;
