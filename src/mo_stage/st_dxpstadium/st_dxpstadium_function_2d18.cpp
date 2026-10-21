#pragma force_active on
extern "C" {
extern char lbl_83_bss_14[];
extern char lbl_83_data_3A8[];
extern char lbl_83_bss_8[];
void fn_83_2D7C();
void __ct__11stClassInfoFv(void *);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void *, int, void *);
void __register_global_object(void *object, void *destructor, void *chain);
}

extern "C" void fn_83_2D18() {
    __ct__11stClassInfoFv(lbl_83_bss_14);
    *(void **)lbl_83_bss_14 = lbl_83_data_3A8;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_83_bss_14, 0x2e, lbl_83_bss_14);
    __register_global_object(lbl_83_bss_14, (void *)fn_83_2D7C, lbl_83_bss_8);
}

__declspec(section ".ctors") extern void* const fn_83_2D18_ctor = (void*)fn_83_2D18;
