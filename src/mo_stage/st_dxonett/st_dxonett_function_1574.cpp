#pragma force_active on
extern "C" {
extern char lbl_78_bss_14[];
extern char lbl_78_bss_8[];
extern char lbl_78_data_4E8[];
void __ct__11stClassInfoFv(void* self);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void fn_78_15D8(void);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_78_1574() {
    __ct__11stClassInfoFv(lbl_78_bss_14);
    *(void**)lbl_78_bss_14 = (void*)lbl_78_data_4E8;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_78_bss_14, 0x2c, lbl_78_bss_14);
    __register_global_object(lbl_78_bss_14, (void*)fn_78_15D8, lbl_78_bss_8);
}

__declspec(section ".ctors") extern void* const fn_78_1574_ctor = (void*)fn_78_1574;
