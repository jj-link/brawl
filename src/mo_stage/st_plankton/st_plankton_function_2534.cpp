#pragma force_active on
extern "C" {
extern char lbl_74_bss_14[4];
extern char lbl_74_data_5E0[];
extern char lbl_74_bss_8[12];

void __ct__11stClassInfoFv(void*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, int, void*);
void* fn_74_2598(void*, int);
void* __register_global_object(void*, void*, void*);

void fn_74_2534() {
    __ct__11stClassInfoFv(lbl_74_bss_14);
    *(void**)lbl_74_bss_14 = lbl_74_data_5E0;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        lbl_74_bss_14, 0x25, lbl_74_bss_14);
    __register_global_object(
        lbl_74_bss_14, (void*)fn_74_2598, lbl_74_bss_8);
}
}

__declspec(section ".ctors") extern void* const fn_74_2534_ctor = (void*)fn_74_2534;
