#pragma force_active on
extern "C" {
    extern char lbl_66_bss_14[];
    extern char lbl_66_bss_8[];
    extern char lbl_66_data_540[];
    void __ct__11stClassInfoFv(void* self);
    void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
    void fn_66_2B48(void);
    void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_66_2AE4(void) {
    __ct__11stClassInfoFv(lbl_66_bss_14);
    *(void**)lbl_66_bss_14 = lbl_66_data_540;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_66_bss_14, 0x1d, lbl_66_bss_14);
    __register_global_object(lbl_66_bss_14, (void*)fn_66_2B48, lbl_66_bss_8);
}

__declspec(section ".ctors") extern void* const fn_66_2AE4_ctor = (void*)fn_66_2AE4;
