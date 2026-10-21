#pragma force_active on
extern "C" {
typedef struct stClassInfo {
    unsigned int value;
} stClassInfo;

extern stClassInfo lbl_55_bss_14;
extern char lbl_55_data_590[];
extern char lbl_55_bss_8[];

extern void __ct__11stClassInfoFv(stClassInfo *);
extern void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    stClassInfo *, int, stClassInfo *);
extern void fn_55_2410();
extern void __register_global_object(void *, void *, void *);

void fn_55_23AC(void) {
    __ct__11stClassInfoFv(&lbl_55_bss_14);
    *(char **)&lbl_55_bss_14 = lbl_55_data_590;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        &lbl_55_bss_14, 12, &lbl_55_bss_14);
    __register_global_object(&lbl_55_bss_14, (void *)fn_55_2410, lbl_55_bss_8);
}
}

__declspec(section ".ctors") extern void* const fn_55_23AC_ctor = (void*)fn_55_23AC;
