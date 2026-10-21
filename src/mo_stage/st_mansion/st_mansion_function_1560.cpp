#pragma force_active on

extern "C" {
extern void __ct__11stClassInfoFv(void*);
extern void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    void*, int, void*);
extern void* __register_global_object(void*, void*, void*);

extern char lbl_47_bss_14[];
extern char lbl_47_data_5D0[];
extern char lbl_47_bss_8[];

void fn_47_15C4(void);
}

extern "C" void fn_47_1560() {
    __ct__11stClassInfoFv(lbl_47_bss_14);
    *(void**)lbl_47_bss_14 = lbl_47_data_5D0;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        lbl_47_bss_14, 0x4, lbl_47_bss_14);
    __register_global_object(lbl_47_bss_14, fn_47_15C4, lbl_47_bss_8);
}

__declspec(section ".ctors") extern void* const fn_47_1560_ctor = (void*)fn_47_1560;
