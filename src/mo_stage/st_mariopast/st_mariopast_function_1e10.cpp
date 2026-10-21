#pragma force_active on
extern "C" {
extern void* lbl_48_bss_14;
extern unsigned char lbl_48_data_4C8[];
extern unsigned char lbl_48_bss_8[];
void __ct__11stClassInfoFv(void*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, int, void*);
void fn_48_1E74(void*, int);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_48_1E10(void) {
    __ct__11stClassInfoFv(&lbl_48_bss_14);
    lbl_48_bss_14 = (void*)lbl_48_data_4C8;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(&lbl_48_bss_14, 5, &lbl_48_bss_14);
    __register_global_object(&lbl_48_bss_14, (void*)fn_48_1E74, lbl_48_bss_8);
}

__declspec(section ".ctors") extern void* const fn_48_1E10_ctor = (void*)fn_48_1E10;
