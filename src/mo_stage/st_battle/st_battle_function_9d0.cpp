#include <st/st_class_info.h>
#pragma force_active on

extern "C" {
extern stClassInfo lbl_43_bss_14;
extern char lbl_43_data_4E0[];
extern char lbl_43_bss_8[];
extern void __ct__11stClassInfoFv(stClassInfo*);
extern void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    stClassInfo*, Stages::srStageKind, stClassInfo*);
extern void fn_43_A34();
extern void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_43_9D0() {
    __ct__11stClassInfoFv(&lbl_43_bss_14);
    *(void**)&lbl_43_bss_14 = lbl_43_data_4E0;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        &lbl_43_bss_14, Stages::srStageKind(1), &lbl_43_bss_14);
    __register_global_object(&lbl_43_bss_14, (void*)fn_43_A34, lbl_43_bss_8);
}

__declspec(section ".ctors") extern void* const fn_43_9D0_ctor = (void*)fn_43_9D0;
