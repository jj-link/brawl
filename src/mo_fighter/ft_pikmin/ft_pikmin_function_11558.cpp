#pragma force_active on
struct DestructorChain;

extern "C" {
extern void* lbl_113_bss_F4;
extern char lbl_113_bss_E8;

void fn_113_115A0(void* object);
void* fn_113_11518(void* ptr, short count);
void* __register_global_object(void* object, void* destructor, DestructorChain* chain);

void fn_113_11558() {
    fn_113_115A0(&lbl_113_bss_F4);
    __register_global_object(
        &lbl_113_bss_F4,
        (void*)fn_113_11518,
        (DestructorChain*)&lbl_113_bss_E8
    );
}
}

__declspec(section ".ctors") extern void* const fn_113_11558_ctor = (void*)fn_113_11558;
