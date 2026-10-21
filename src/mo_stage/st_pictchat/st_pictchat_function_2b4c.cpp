#pragma force_active on
extern "C" {
extern char lbl_73_bss_8[];
extern char lbl_73_bss_14[];
extern char lbl_73_data_BA0[];
void fn_73_2BB0(void*);
void __ct__11stClassInfoFv(char*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(char*, int, char*);
void* __register_global_object(char*, void*, char*);
}

extern "C" void fn_73_2B4C() {
    __ct__11stClassInfoFv(lbl_73_bss_14);
    *(char**)lbl_73_bss_14 = lbl_73_data_BA0;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_73_bss_14, 0x24, lbl_73_bss_14);
    __register_global_object(lbl_73_bss_14, fn_73_2BB0, lbl_73_bss_8);
}

__declspec(section ".ctors") extern void* const fn_73_2B4C_ctor = (void*)fn_73_2B4C;
