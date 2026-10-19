#pragma force_active on
struct FnObj {
    int a;
    int b;
};

extern "C" {
extern signed char lbl_123_bss_2EC;
extern FnObj lbl_123_bss_2F0;
extern char lbl_123_bss_2D8[];
void fn_27_3BB610(void*);
void fn_27_3BB620(void*, int);
void* __register_global_object(void*, void*, void*);

FnObj* fn_123_8DCC() {
    if (lbl_123_bss_2EC == 0) {
        fn_27_3BB610(&lbl_123_bss_2F0);
        __register_global_object(&lbl_123_bss_2F0, (void*)fn_27_3BB620, lbl_123_bss_2D8);
        lbl_123_bss_2EC = 1;
    }
    return &lbl_123_bss_2F0;
}
}
