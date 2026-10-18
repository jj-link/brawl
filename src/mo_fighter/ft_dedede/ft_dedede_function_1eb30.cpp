#pragma force_active on
struct DededeSingletonStorage { void* primary; void* secondary; };
struct DededeSingletonRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern signed char lbl_117_bss_394;
extern DededeSingletonStorage lbl_117_bss_398;
extern DededeSingletonRegistration lbl_117_bss_480;
extern unsigned char lbl_117_data_3B0C[], lbl_117_data_3AE0[];
extern unsigned char lbl_117_data_3A78[], lbl_117_data_90D0[];
void* fn_117_1538C(void*, short);
void __register_global_object(void*, void*, void*);
DededeSingletonStorage* fn_117_1EB30() {
    if (lbl_117_bss_394 == 0) {
        lbl_117_bss_398.primary = lbl_117_data_3B0C;
        lbl_117_bss_398.secondary = lbl_117_data_3AE0;
        lbl_117_bss_398.primary = lbl_117_data_3A78;
        lbl_117_bss_398.secondary = lbl_117_data_3A78 + 0x10;
        lbl_117_bss_398.primary = lbl_117_data_90D0;
        lbl_117_bss_398.secondary = lbl_117_data_90D0 + 0x10;
        __register_global_object(&lbl_117_bss_398, reinterpret_cast<void*>(fn_117_1538C), &lbl_117_bss_480);
        lbl_117_bss_394 = 1;
    }
    return &lbl_117_bss_398;
}
}
