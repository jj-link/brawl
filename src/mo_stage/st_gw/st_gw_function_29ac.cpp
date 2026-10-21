#pragma force_active on
extern "C" {
extern char lbl_63_data_8C0[];
extern char lbl_63_bss_14[];
extern char lbl_63_bss_8[];
void __ct__11stClassInfoFv(void* self);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void* fn_63_2A10(void* self, int flags);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_63_29AC(void)
{
    __ct__11stClassInfoFv(lbl_63_bss_14);
    *(void**)lbl_63_bss_14 = lbl_63_data_8C0;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_63_bss_14, 0x18, lbl_63_bss_14);
    __register_global_object(lbl_63_bss_14, (void*)fn_63_2A10, lbl_63_bss_8);
}
}

__declspec(section ".ctors") extern void* const fn_63_29AC_ctor = (void*)fn_63_29AC;
