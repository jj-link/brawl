#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_1078;
extern int lbl_96_bss_107C;
extern char lbl_96_bss_F40[12];
void fn_27_39A924(void* p);
void* fn_27_39A934(void* ptr, int size);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_96_2060C() {
    if (lbl_96_bss_1078 == 0) {
        fn_27_39A924(&lbl_96_bss_107C);
        __register_global_object(&lbl_96_bss_107C, (void*)fn_27_39A934, lbl_96_bss_F40);
        lbl_96_bss_1078 = 1;
    }
    return &lbl_96_bss_107C;
}
}
