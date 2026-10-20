#pragma force_active on

struct Bss48 {
    char c;
    char pad[3];
    void* ptr;
};

extern "C" {
extern char lbl_70_bss_40;
extern struct Bss48 lbl_70_bss_48;
extern char lbl_70_bss_18[];
extern char lbl_70_data_3250[];
extern char lbl_70_data_31F8[];
void* fn_70_83F4(void*, int);
void* __register_global_object(void*, void*, void*);
}

extern "C" void* fn_70_8330() {
    if (!lbl_70_bss_40) {
        lbl_70_bss_48.ptr = (void*)lbl_70_data_3250;
        lbl_70_bss_48.c = 1;
        lbl_70_bss_48.ptr = (void*)lbl_70_data_31F8;
        __register_global_object((void*)&lbl_70_bss_48, fn_70_83F4, (void*)lbl_70_bss_18);
        lbl_70_bss_40 = 1;
    }
    return (void*)&lbl_70_bss_48;
}
