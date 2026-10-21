#pragma force_active on
extern "C" {
extern void* lbl_61_bss_14;
extern char lbl_61_data_AB8[];
extern char lbl_61_bss_8[];

void __ct__11stClassInfoFv(void*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, int, void*);
void* fn_61_226C(void*, int);
void* __register_global_object(void*, void*, void*);

void fn_61_2208() {
    __ct__11stClassInfoFv(&lbl_61_bss_14);
    lbl_61_bss_14 = lbl_61_data_AB8;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        &lbl_61_bss_14, 0x16, &lbl_61_bss_14);
    __register_global_object(
        &lbl_61_bss_14, (void*)fn_61_226C, lbl_61_bss_8);
}
}

__declspec(section ".ctors") extern void* const fn_61_2208_ctor = (void*)fn_61_2208;
