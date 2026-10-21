#pragma force_active on
extern "C" {
extern void* lbl_84_bss_14;
extern char lbl_84_data_4B8[];
extern char lbl_84_bss_8[];

void __ct__11stClassInfoFv(void*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, int, void*);
void fn_84_3F50();
void* __register_global_object(void*, void*, void*);

void fn_84_3EEC() {
    __ct__11stClassInfoFv(&lbl_84_bss_14);
    lbl_84_bss_14 = lbl_84_data_4B8;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        &lbl_84_bss_14, 0x32, &lbl_84_bss_14);
    __register_global_object(
        &lbl_84_bss_14, (void*)fn_84_3F50, lbl_84_bss_8);
}
}

__declspec(section ".ctors") extern void* const fn_84_3EEC_ctor = (void*)fn_84_3EEC;
