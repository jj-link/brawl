#pragma force_active on
struct ObjectSlot {
    char flag;
    char pad[3];
    void *data;
};
struct ChainSlot {
    void *next;
    void *destructor;
    void *object;
};

extern "C" {
    extern char lbl_54_bss_58;
    extern ObjectSlot lbl_54_bss_60;
    extern ChainSlot lbl_54_bss_28;
    extern char lbl_54_data_1280[];
    extern char lbl_54_data_1228[];
    void *__register_global_object(void *object, void *destructor, ChainSlot *chain);
    void *fn_54_52C8(void *ptr, int size);
}

extern "C" void *fn_54_5204() {
    if (!lbl_54_bss_58) {
        lbl_54_bss_60.data = (void*)lbl_54_data_1280;
        lbl_54_bss_60.flag = 1;
        lbl_54_bss_60.data = (void*)lbl_54_data_1228;
        __register_global_object((void*)&lbl_54_bss_60, fn_54_52C8, &lbl_54_bss_28);
        lbl_54_bss_58 = 1;
    }
    return (void*)&lbl_54_bss_60;
}
