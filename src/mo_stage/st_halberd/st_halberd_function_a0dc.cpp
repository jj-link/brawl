#pragma force_active on
struct Obj40 {
    signed char a;
    void *b;
};

extern "C" {
void* fn_57_A1A0(void* p, int flag);
void* __register_global_object(void* object, void* destructor, void* chain);
extern signed char lbl_57_bss_3C;
extern Obj40 lbl_57_bss_40;
extern void* lbl_57_bss_18[3];
extern char lbl_57_data_1BE0[];
extern char lbl_57_data_1B88[];
}

extern "C" void* fn_57_A0DC() {
    if (!lbl_57_bss_3C) {
        lbl_57_bss_40.b = (void*)lbl_57_data_1BE0;
        lbl_57_bss_40.a = 1;
        lbl_57_bss_40.b = (void*)lbl_57_data_1B88;
        __register_global_object(&lbl_57_bss_40, (void*)fn_57_A1A0, &lbl_57_bss_18);
        lbl_57_bss_3C = 1;
    }
    return &lbl_57_bss_40;
}
