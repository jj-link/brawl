#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern char lbl_27_data_88818[0x40];
extern GlobalObject lbl_27_bss_7D64;
extern char lbl_27_bss_7D58[0xC];
void* fn_27_32E230(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_32E270() {
    lbl_27_bss_7D64.vtable = 0;
    lbl_27_bss_7D64.vtable = (void*)lbl_27_data_88818;
    __register_global_object(&lbl_27_bss_7D64, (void*)fn_27_32E230, lbl_27_bss_7D58);
}
}

__declspec(section ".ctors") extern void* const fn_27_32E270_ctor = (void*)fn_27_32E270;
