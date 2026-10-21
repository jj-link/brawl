#pragma force_active on
extern "C" {
extern unsigned char lbl_57_bss_14[];
extern unsigned char lbl_57_bss_8[];
extern unsigned char lbl_57_data_560[];
void __ct__11stClassInfoFv(void *obj);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void *obj, int kind, void *info);
void fn_57_38CC(void);
void *__register_global_object(void *object, void *destructor, void *chain);

void fn_57_3868(void)
{
    __ct__11stClassInfoFv(lbl_57_bss_14);
    *(void **)lbl_57_bss_14 = lbl_57_data_560;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_57_bss_14, 0xe, lbl_57_bss_14);
    __register_global_object(lbl_57_bss_14, (void *)fn_57_38CC, lbl_57_bss_8);
}
}

__declspec(section ".ctors") extern void* const fn_57_3868_ctor = (void*)fn_57_3868;
