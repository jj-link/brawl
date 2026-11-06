#pragma force_active on

extern "C" {

extern char lbl_27_data_8BC20[0x40];
extern char *lbl_27_bss_7E24;
extern char lbl_27_bss_7E18[0xC];
void fn_27_33D15C(void *, int);
void __register_global_object(void *, void *, void *);
void fn_27_33D19C(void);

}

void fn_27_33D19C(void) {
    lbl_27_bss_7E24 = 0;
    lbl_27_bss_7E24 = lbl_27_data_8BC20;
    __register_global_object(&lbl_27_bss_7E24, (void *)fn_27_33D15C, lbl_27_bss_7E18);
}

__declspec(section ".ctors") extern void* const fn_27_33D19C_ctor = (void*)fn_27_33D19C;
