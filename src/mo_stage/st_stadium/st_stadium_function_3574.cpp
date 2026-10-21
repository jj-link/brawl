#include <st/st_class_info.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_59_bss_14[];
extern unsigned char lbl_59_data_5D0[];
extern unsigned char lbl_59_bss_8[];
extern void fn_59_35D8();
extern void __ct__11stClassInfoFv(void*);
extern void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, int, void*);
extern void __register_global_object(void*, void*, void*);
}

extern "C" void fn_59_3574() {
    __ct__11stClassInfoFv(lbl_59_bss_14);
    *(void**)lbl_59_bss_14 = lbl_59_data_5D0;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_59_bss_14, 0x14, lbl_59_bss_14);
    __register_global_object(lbl_59_bss_14, (void*)fn_59_35D8, lbl_59_bss_8);
}

__declspec(section ".ctors") extern void* const fn_59_3574_ctor = (void*)fn_59_3574;
