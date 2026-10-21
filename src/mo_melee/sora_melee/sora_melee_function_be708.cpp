#pragma force_active on
extern "C" {
extern void* __vt__10soNullable[];
extern unsigned char lbl_27_data_9BC8[0x1C];
extern unsigned char lbl_27_data_177C8[0x1C];
extern unsigned char lbl_27_bss_2B98[0xC];
void* fn_27_BE6C8(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* chain);
}

struct Obj {
    void* vt;
    unsigned char flag;
    void* ptr;
};

extern Obj lbl_27_bss_2BA4;

extern "C" void fn_27_BE708() {
    lbl_27_bss_2BA4.vt = __vt__10soNullable;
    lbl_27_bss_2BA4.ptr = lbl_27_data_9BC8;
    lbl_27_bss_2BA4.vt = lbl_27_data_9BC8 + 8;
    lbl_27_bss_2BA4.flag = 0;
    lbl_27_bss_2BA4.ptr = lbl_27_data_177C8;
    lbl_27_bss_2BA4.vt = lbl_27_data_177C8 + 8;
    __register_global_object(&lbl_27_bss_2BA4, (void*)fn_27_BE6C8, lbl_27_bss_2B98);
}

__declspec(section ".ctors") extern void* const fn_27_BE708_ctor = (void*)fn_27_BE708;
