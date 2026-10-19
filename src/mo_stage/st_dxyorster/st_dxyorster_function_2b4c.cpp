#pragma force_active on
struct Holder {
    unsigned char flag;
    void* ptr;
};

extern "C" {
extern signed char lbl_76_bss_30;
extern unsigned char lbl_76_bss_18[0xC];
extern Holder lbl_76_bss_38;
extern unsigned char lbl_76_data_1098[0x38];
extern unsigned char lbl_76_data_1040[0x38];
void* fn_76_2C10(void* ptr, int size);
void* __register_global_object(void* object, void* (*destructor)(void*, int), void* chain);
}

extern "C" void* fn_76_2B4C() {
    if (!lbl_76_bss_30) {
        lbl_76_bss_38.ptr = lbl_76_data_1098;
        lbl_76_bss_38.flag = 1;
        lbl_76_bss_38.ptr = lbl_76_data_1040;
        __register_global_object(&lbl_76_bss_38, fn_76_2C10, lbl_76_bss_18);
        lbl_76_bss_30 = 1;
    }
    return &lbl_76_bss_38;
}
