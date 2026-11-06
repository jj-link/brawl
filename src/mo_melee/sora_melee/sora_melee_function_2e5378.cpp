#pragma force_active on

struct GlobalObj {
    void* vtbl;
};

extern "C" {
extern char lbl_27_data_7D0B0[];
extern GlobalObj lbl_27_bss_7494;
extern char lbl_27_bss_7488[12];
void fn_27_2E5338(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_2E5378(void);
}

void fn_27_2E5378() {
    lbl_27_bss_7494.vtbl = 0;
    lbl_27_bss_7494.vtbl = (void*)lbl_27_data_7D0B0;
    __register_global_object(&lbl_27_bss_7494, (void*)fn_27_2E5338, lbl_27_bss_7488);
}

__declspec(section ".ctors") extern void* const fn_27_2E5378_ctor = (void*)fn_27_2E5378;
