#pragma force_active on
extern "C" {
    void __ct__11stClassInfoFv(void*);
    void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, int, void*);
    void __register_global_object(void*, void*, void*);
    void fn_71_257C(void*, int);
    extern unsigned char lbl_71_data_6F8[];
    extern unsigned char lbl_71_bss_14[];
    extern void* lbl_71_bss_8[];

    void fn_71_2518() {
        __ct__11stClassInfoFv(lbl_71_bss_14);
        *(void**)lbl_71_bss_14 = lbl_71_data_6F8;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_71_bss_14, 0x22, lbl_71_bss_14);
        __register_global_object(lbl_71_bss_14, fn_71_257C, lbl_71_bss_8);
    }
}

__declspec(section ".ctors") extern void* const fn_71_2518_ctor = (void*)fn_71_2518;
