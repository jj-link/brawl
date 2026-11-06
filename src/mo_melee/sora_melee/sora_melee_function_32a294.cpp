#pragma force_active on

extern "C" {

extern char lbl_27_data_880E8[0x40];
extern char lbl_27_bss_7CF0[0xC];
void fn_27_32A254(void*, int);
void __register_global_object(void*, void*, void*);

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_7CFC;

void fn_27_32A294(void) {
    lbl_27_bss_7CFC.vtable = 0;
    lbl_27_bss_7CFC.vtable = &lbl_27_data_880E8;
    __register_global_object(&lbl_27_bss_7CFC, fn_27_32A254, lbl_27_bss_7CF0);
}

}

__declspec(section ".ctors") extern void* const fn_27_32A294_ctor = (void*)fn_27_32A294;
