#include <st/st_class_info.h>
#pragma force_active on

extern "C" char lbl_72_data_4D0[];
extern "C" void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    stClassInfo*, Stages::srStageKind, stClassInfo*);
extern "C" void __ct__11stClassInfoFv(stClassInfo*);
extern "C" void fn_72_107C(void*, int);
extern "C" void* __register_global_object(void*, void*, void*);

extern "C" stClassInfo lbl_72_bss_14;
extern "C" char lbl_72_bss_8[12];

extern "C" void fn_72_1018() {
    __ct__11stClassInfoFv(&lbl_72_bss_14);
    *(void**)&lbl_72_bss_14 = lbl_72_data_4D0;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        &lbl_72_bss_14, Stages::srStageKind(0x23), &lbl_72_bss_14);
    __register_global_object(&lbl_72_bss_14, (void*)fn_72_107C, lbl_72_bss_8);
}

__declspec(section ".ctors") extern void* const fn_72_1018_ctor = (void*)fn_72_1018;
