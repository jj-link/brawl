#pragma force_active on
extern "C" {
extern void* lbl_11_bss_8;
void fn_11_7824(void*);
void exit__6gfTaskFv(void*);

void fn_11_4D8(void* self) {
    if (lbl_11_bss_8 != 0) {
        fn_11_7824(lbl_11_bss_8);
        lbl_11_bss_8 = 0;
    }
    exit__6gfTaskFv(self);
}
}
