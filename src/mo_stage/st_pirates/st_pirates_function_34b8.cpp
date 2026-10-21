#include <st/st_class_info.h>
#pragma force_active on

extern "C" void __ct__11stClassInfoFv(stClassInfo*);
extern "C" void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    stClassInfo*, int, stClassInfo*);
extern "C" void fn_52_351C();
extern "C" void __register_global_object(void*, void*, void*);

extern stClassInfo lbl_52_bss_14;
extern char lbl_52_bss_8[];
extern char lbl_52_data_7E8[];

extern "C" void fn_52_34B8()
{
    __ct__11stClassInfoFv(&lbl_52_bss_14);
    *reinterpret_cast<void**>(&lbl_52_bss_14) = lbl_52_data_7E8;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        &lbl_52_bss_14, 9, &lbl_52_bss_14);
    __register_global_object(&lbl_52_bss_14,
                             reinterpret_cast<void*>(fn_52_351C),
                             lbl_52_bss_8);
}

__declspec(section ".ctors") extern void* const fn_52_34B8_ctor = (void*)fn_52_34B8;
