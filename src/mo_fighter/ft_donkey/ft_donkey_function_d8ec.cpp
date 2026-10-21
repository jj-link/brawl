#pragma force_active on
typedef void DestructorChain;

extern "C" {
extern void* lbl_92_bss_1E4;
extern char lbl_92_bss_1D8[];
void fn_92_D934(void** object);
void* fn_92_D8AC(void* ptr, short size);
void* __register_global_object(void* object, void* destructor, DestructorChain* chain);

void fn_92_D8EC() {
    fn_92_D934(&lbl_92_bss_1E4);
    __register_global_object(&lbl_92_bss_1E4, (void*)fn_92_D8AC, (DestructorChain*)lbl_92_bss_1D8);
}
}

__declspec(section ".ctors") extern void* const fn_92_D8EC_ctor = (void*)fn_92_D8EC;
