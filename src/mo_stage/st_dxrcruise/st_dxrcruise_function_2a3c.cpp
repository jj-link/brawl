#pragma force_active on
extern "C" {
extern void* lbl_80_bss_14;
extern void* lbl_80_data_538[];
extern unsigned char lbl_80_bss_8[12];

void __ct__11stClassInfoFv(void*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, int, void*);
void fn_80_2AA0(void*, int);
void* __register_global_object(void*, void*, void*);

void fn_80_2A3C() {
    __ct__11stClassInfoFv(&lbl_80_bss_14);
    lbl_80_bss_14 = lbl_80_data_538;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        &lbl_80_bss_14, 47, &lbl_80_bss_14);
    __register_global_object(
        &lbl_80_bss_14, (void*)fn_80_2AA0, lbl_80_bss_8);
}
}

__declspec(section ".ctors") extern void* const fn_80_2A3C_ctor = (void*)fn_80_2A3C;
