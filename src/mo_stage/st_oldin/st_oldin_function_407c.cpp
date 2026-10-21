#pragma force_active on

extern "C" {
extern unsigned char lbl_53_data_660[];
extern unsigned char lbl_53_bss_14[];
extern unsigned char lbl_53_bss_8[];

void __ct__11stClassInfoFv(void*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    void*, int, void*);
void* __register_global_object(void*, void*, void*);
void* fn_53_40E0(void*, int);
}

extern "C" void fn_53_407C() {
    __ct__11stClassInfoFv(lbl_53_bss_14);
    *(void**)lbl_53_bss_14 = lbl_53_data_660;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        lbl_53_bss_14, 0x33, lbl_53_bss_14);
    __register_global_object(lbl_53_bss_14, fn_53_40E0, lbl_53_bss_8);
}

__declspec(section ".ctors") extern void* const fn_53_407C_ctor = (void*)fn_53_407C;
