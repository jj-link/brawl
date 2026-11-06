#pragma force_active on

extern "C" {

struct GlobalBase {
    void* vtbl;
};

extern char lbl_27_data_9E078[];
extern char lbl_27_bss_8B38[0xC];
extern GlobalBase lbl_27_bss_8B44;

void* fn_27_3AA670(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_3AA6B0() {
    lbl_27_bss_8B44.vtbl = 0;
    lbl_27_bss_8B44.vtbl = lbl_27_data_9E078;
    __register_global_object(&lbl_27_bss_8B44, fn_27_3AA670, lbl_27_bss_8B38);
}

}

__declspec(section ".ctors") extern void* const fn_27_3AA6B0_ctor = (void*)fn_27_3AA6B0;
