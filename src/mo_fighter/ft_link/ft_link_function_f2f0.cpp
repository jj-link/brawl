#pragma force_active on
extern "C" {
extern unsigned char lbl_93_bss_14C[];
extern unsigned char lbl_93_bss_140[];

void fn_93_F338(void **ptr);
void *fn_93_F2AC(void *p, short size);
void *__register_global_object(void *object, void *destructor, void *chain);

void fn_93_F2F0(void) {
    fn_93_F338((void **)lbl_93_bss_14C);
    __register_global_object(
        (void *)lbl_93_bss_14C,
        (void *)fn_93_F2AC,
        (void *)lbl_93_bss_140
    );
}
}

__declspec(section ".ctors") extern void* const fn_93_F2F0_ctor = (void*)fn_93_F2F0;
