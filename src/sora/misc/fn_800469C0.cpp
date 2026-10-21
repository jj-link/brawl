#pragma force_active on
extern "C" {
void __register_global_object(void*, void (*)(void*), void*);
extern char lbl_8042B680[];
extern void fn_800469E4(void*);
extern char lbl_804977C0[];
extern void* lbl_805A00C0;

void fn_800469C0(void) {
    lbl_805A00C0 = lbl_8042B680;
    __register_global_object(&lbl_805A00C0, fn_800469E4, lbl_804977C0);
}
}

__declspec(section ".ctors") extern void* const fn_800469C0_ctor = (void*)fn_800469C0;
