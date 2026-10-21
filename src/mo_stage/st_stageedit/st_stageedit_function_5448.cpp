#pragma force_active on
extern "C" {
void __ct__11stClassInfoFv(void* self);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void fn_85_54AC(void);
void* __register_global_object(void* object, void* destructor, void* chain);
extern char lbl_85_data_718[];
extern char lbl_85_bss_14[];
extern char lbl_85_bss_8[];
}

extern "C" void fn_85_5448(void)
{
    __ct__11stClassInfoFv(lbl_85_bss_14);
    *(void**)lbl_85_bss_14 = lbl_85_data_718;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_85_bss_14, 0x35, lbl_85_bss_14);
    __register_global_object(lbl_85_bss_14, (void*)fn_85_54AC, lbl_85_bss_8);
}

__declspec(section ".ctors") extern void* const fn_85_5448_ctor = (void*)fn_85_5448;
