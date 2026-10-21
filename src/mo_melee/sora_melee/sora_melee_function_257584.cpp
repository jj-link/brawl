#pragma force_active on
extern "C" {
extern char lbl_27_data_53228[];
extern char lbl_27_bss_59E0[];

void fn_27_257584(void) {
    *(char**)lbl_27_bss_59E0 = lbl_27_data_53228;
}
}

__declspec(section ".ctors") extern void* const fn_27_257584_ctor = (void*)fn_27_257584;
