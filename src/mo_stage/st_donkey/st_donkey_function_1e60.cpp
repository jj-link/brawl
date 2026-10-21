#pragma force_active on
extern "C" void __ct__11stClassInfoFv(void* self);
extern "C" void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);
extern "C" void fn_50_1EC4();
extern "C" char lbl_50_bss_14[];
extern "C" char lbl_50_bss_8[];
extern "C" char lbl_50_data_7C8[];

extern "C" void fn_50_1E60() {
    __ct__11stClassInfoFv(lbl_50_bss_14);
    *(void**)lbl_50_bss_14 = lbl_50_data_7C8;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_50_bss_14, 7, lbl_50_bss_14);
    __register_global_object(lbl_50_bss_14, (void*)fn_50_1EC4, lbl_50_bss_8);
}

__declspec(section ".ctors") extern void* const fn_50_1E60_ctor = (void*)fn_50_1E60;
