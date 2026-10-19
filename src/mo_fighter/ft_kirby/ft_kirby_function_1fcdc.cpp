#pragma force_active on
extern "C" {
extern unsigned char lbl_96_bss_FD0[];
extern unsigned char lbl_96_bss_FD4[];
extern unsigned char lbl_96_bss_E44[];

void fn_27_3244C4(void*);
void fn_27_3244D4(void*, int);
void* __register_global_object(void*, void*, void*);
}

extern "C" void* fn_96_1FCDC() {
    if (*(signed char*)lbl_96_bss_FD0 == 0) {
        fn_27_3244C4(lbl_96_bss_FD4);
        __register_global_object(
            lbl_96_bss_FD4,
            (void*)fn_27_3244D4,
            lbl_96_bss_E44
        );
        *(unsigned char*)lbl_96_bss_FD0 = 1;
    }
    return lbl_96_bss_FD4;
}
