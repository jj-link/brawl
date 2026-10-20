#pragma force_active on
struct Obj70 {
    signed char a;
    int b;
};

extern "C" {
void* fn_56_50EC(void* p, int flag);
void* __register_global_object(void* object, void* destructor, void* chain);
extern signed char lbl_56_bss_68;
extern Obj70 lbl_56_bss_70;
extern void* lbl_56_bss_28[3];
extern char lbl_56_data_1698[];
extern char lbl_56_data_16F0[];
}

extern "C" void* fn_56_5028() {
    if (!lbl_56_bss_68) {
        lbl_56_bss_70.b = (int)lbl_56_data_16F0;
        lbl_56_bss_70.a = 1;
        lbl_56_bss_70.b = (int)lbl_56_data_1698;
        __register_global_object(&lbl_56_bss_70, (void*)fn_56_50EC, &lbl_56_bss_28);
        lbl_56_bss_68 = 1;
    }
    return &lbl_56_bss_70;
}
