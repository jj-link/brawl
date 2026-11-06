#pragma force_active on

extern "C" {

extern char lbl_27_data_32698[];
void fn_27_191FA0(void*, int);
void __register_global_object(void*, void*, void*);

struct GlobalBase {
    void* vtbl;
};

extern GlobalBase lbl_27_bss_4FCC;
extern char lbl_27_bss_4FC0[];

void fn_27_191FE0() {
    lbl_27_bss_4FCC.vtbl = 0;
    lbl_27_bss_4FCC.vtbl = lbl_27_data_32698;
    __register_global_object(&lbl_27_bss_4FCC, (void*)fn_27_191FA0, lbl_27_bss_4FC0);
}

}

__declspec(section ".ctors") extern void* const fn_27_191FE0_ctor = (void*)fn_27_191FE0;
