#pragma force_active on
struct MetaKnightGlobals {
    unsigned char chain1[0xC];
    unsigned char obj1[0x138];
    unsigned char chain2[0xC];
    unsigned char obj2[0x8];
};
#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern MetaKnightGlobals lbl_111_bss_8;
void* fn_111_C41C(void*);
void* fn_111_C464(void*);
void* fn_111_82FC(void*, int);
void* fn_111_C4BC(void*, short);
void __register_global_object(void*, void*, void*);

void fn_111_C3B8() {
    MetaKnightGlobals* base = &lbl_111_bss_8;
    unsigned char (MetaKnightGlobals::*chain)[0xC] = &MetaKnightGlobals::chain1;
    fn_111_C41C(base->obj1);
    __register_global_object(base->obj1, fn_111_82FC, &(base->*chain));
    fn_111_C464(base->obj2);
    __register_global_object(base->obj2, fn_111_C4BC, base->chain2);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_111_C3B8_ctor = (void*)fn_111_C3B8;
