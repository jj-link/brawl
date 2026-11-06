#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern GlobalObject lbl_27_bss_8054;
extern char lbl_27_bss_8048[0xC];
extern char lbl_27_data_8F450[];
void* fn_27_3574CC(void*, int);
void* __register_global_object(void*, void*, void*);

void fn_27_35750C() {
    lbl_27_bss_8054.vtable = 0;
    lbl_27_bss_8054.vtable = lbl_27_data_8F450;
    __register_global_object(&lbl_27_bss_8054, (void*)fn_27_3574CC, lbl_27_bss_8048);
}

}

__declspec(section ".ctors") extern void* const fn_27_35750C_ctor = (void*)fn_27_35750C;
