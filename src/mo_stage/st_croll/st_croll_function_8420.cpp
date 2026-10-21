#pragma force_active on
namespace Stages {
enum srStageKind { srStageKind_Config = 0x39 };
}

class stClassInfo;

extern "C" {
extern char lbl_90_bss_20[];
extern char lbl_90_bss_14[];
extern char lbl_90_data_2DD8[];
void fn_90_8484();
void __ct__11stClassInfoFv(stClassInfo* self);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(stClassInfo* self, Stages::srStageKind kind, stClassInfo* info);
void __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_90_8420() {
    __ct__11stClassInfoFv((stClassInfo*)lbl_90_bss_20);
    *(char**)lbl_90_bss_20 = lbl_90_data_2DD8;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo((stClassInfo*)lbl_90_bss_20, (Stages::srStageKind)0x39, (stClassInfo*)lbl_90_bss_20);
    __register_global_object(lbl_90_bss_20, (void*)fn_90_8484, lbl_90_bss_14);
}

__declspec(section ".ctors") extern void* const fn_90_8420_ctor = (void*)fn_90_8420;
