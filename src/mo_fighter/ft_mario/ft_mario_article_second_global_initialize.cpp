struct MarioSecondArticleRegistration { void* next; void* object; void* destructor; };
struct MarioSecondArticleGlobalObject { void* vtable; };
extern "C" {
extern unsigned char lbl_91_data_99C0[];
MarioSecondArticleRegistration lbl_91_bss_398;
MarioSecondArticleGlobalObject lbl_91_bss_3A4;
MarioSecondArticleGlobalObject* fn_91_16DDC(MarioSecondArticleGlobalObject*);
void __register_global_object(void*, void*, void*);
void* fn_91_16D54(void* object, short deleting) {
    if (object != 0 && deleting > 0) operator delete(object);
    return object;
}
void fn_91_16D94() {
    fn_91_16DDC(&lbl_91_bss_3A4);
    __register_global_object(&lbl_91_bss_3A4, reinterpret_cast<void*>(fn_91_16D54), &lbl_91_bss_398);
}
#pragma dont_inline on
MarioSecondArticleGlobalObject* fn_91_16DDC(MarioSecondArticleGlobalObject* object) {
    object->vtable = lbl_91_data_99C0;
    return object;
}
#pragma dont_inline reset
}
__declspec(section ".ctors") extern void (*const marioSecondArticleInitializer)() = fn_91_16D94;
