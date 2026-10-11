struct MarioArticleGlobalRegistration { void* next; void* object; void* destructor; };
struct MarioArticleGlobalObject { void* vtable; };
extern "C" {
extern unsigned char lbl_91_data_9300[];
MarioArticleGlobalRegistration lbl_91_bss_330;
MarioArticleGlobalObject lbl_91_bss_33C;
void* fn_91_14494(void*, short);
MarioArticleGlobalObject* fn_91_1451C(MarioArticleGlobalObject*);
void __register_global_object(void*, void*, void*);
void fn_91_144D4() {
    fn_91_1451C(&lbl_91_bss_33C);
    __register_global_object(&lbl_91_bss_33C, reinterpret_cast<void*>(fn_91_14494), &lbl_91_bss_330);
}
#pragma dont_inline on
MarioArticleGlobalObject* fn_91_1451C(MarioArticleGlobalObject* object) {
    object->vtable = lbl_91_data_9300;
    return object;
}
#pragma dont_inline reset
}
__declspec(section ".ctors") extern void (*const marioArticleInitializer)() = fn_91_144D4;
