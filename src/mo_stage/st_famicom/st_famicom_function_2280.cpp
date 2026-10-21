#pragma force_active on
struct stClassInfoLike {
    void* vtbl;
};

extern "C" {
extern stClassInfoLike lbl_68_bss_14;
extern char lbl_68_data_538[];
extern char lbl_68_bss_8[];

void __ct__11stClassInfoFv(stClassInfoLike*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    stClassInfoLike*, int, stClassInfoLike*);
stClassInfoLike* fn_68_22E4(stClassInfoLike*, int);
void* __register_global_object(void*, void*, void*);

void fn_68_2280() {
    __ct__11stClassInfoFv(&lbl_68_bss_14);
    lbl_68_bss_14.vtbl = lbl_68_data_538;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        &lbl_68_bss_14, 0x1f, &lbl_68_bss_14);
    __register_global_object(
        &lbl_68_bss_14, (void*)fn_68_22E4, lbl_68_bss_8);
}
}

__declspec(section ".ctors") extern void* const fn_68_2280_ctor = (void*)fn_68_2280;
