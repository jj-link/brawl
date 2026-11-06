#pragma force_active on

extern "C" {

struct GlobalObject {
    void* vtable;
};

extern char lbl_27_data_32A08[];
extern GlobalObject lbl_27_bss_503C;
extern char lbl_27_bss_5030[0xC];
void fn_27_192CE4(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_192D24(void) {
    lbl_27_bss_503C.vtable = 0;
    lbl_27_bss_503C.vtable = (void*)lbl_27_data_32A08;
    __register_global_object(&lbl_27_bss_503C, (void*)fn_27_192CE4, lbl_27_bss_5030);
}

}

__declspec(section ".ctors") extern void* const fn_27_192D24_ctor = (void*)fn_27_192D24;
