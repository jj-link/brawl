#pragma force_active on
typedef int s32;

extern "C" {
extern unsigned char lbl_46_bss_14[];
extern unsigned char lbl_46_data_C28[];
extern unsigned char lbl_46_bss_8[];

void __ct__11stClassInfoFv(void*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    void*, s32, void*);
void fn_46_4400(void);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_46_439C(void) {
    __ct__11stClassInfoFv(lbl_46_bss_14);
    *(void**)lbl_46_bss_14 = lbl_46_data_C28;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        lbl_46_bss_14, 3, lbl_46_bss_14);
    __register_global_object(
        lbl_46_bss_14, (void*)fn_46_4400, lbl_46_bss_8);
}

__declspec(section ".ctors") extern void* const fn_46_439C_ctor = (void*)fn_46_439C;
