#pragma force_active on
extern "C" {
extern unsigned char lbl_113_bss_2FC[];
extern unsigned char lbl_113_bss_2F0[];

void fn_113_2AAE0(void*);
void* fn_113_2AA58(void*, int);
void* __register_global_object(void*, void* (*)(void*, int), void*);

void fn_113_2AA98() {
    fn_113_2AAE0(lbl_113_bss_2FC);
    __register_global_object(
        lbl_113_bss_2FC,
        fn_113_2AA58,
        lbl_113_bss_2F0
    );
}
}

__declspec(section ".ctors") extern void* const fn_113_2AA98_ctor = (void*)fn_113_2AA98;
