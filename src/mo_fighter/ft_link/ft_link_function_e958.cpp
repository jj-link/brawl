#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct LinkGlobals {
    unsigned char chain1[0xC];
    unsigned char obj1[0xE8];
    unsigned char chain2[0xC];
    unsigned char obj2[0xC];
};

extern "C" {
extern LinkGlobals lbl_93_bss_8;

void fn_93_E9BC(void*);
void fn_93_AD34(void*, short);
void fn_93_EA04(void*);
void fn_93_EA5C(void*, short);
void __register_global_object(void*, void*, void*);

void fn_93_E958() {
    LinkGlobals* base = &lbl_93_bss_8;
    unsigned char (LinkGlobals::*chain)[0xC] = &LinkGlobals::chain1;

    fn_93_E9BC(base->obj1);
    __register_global_object(base->obj1, fn_93_AD34, &(base->*chain));

    fn_93_EA04(base->obj2);
    __register_global_object(base->obj2, fn_93_EA5C, base->chain2);
}
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_93_E958_ctor = (void*)fn_93_E958;
