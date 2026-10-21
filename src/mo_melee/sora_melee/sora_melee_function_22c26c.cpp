#pragma force_active on
extern "C" {
extern char lbl_27_bss_5794[];
extern char lbl_27_data_4B108[];
extern char lbl_27_bss_5788[];
extern void __ct__11stClassInfoFv(void* self);
extern void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
extern void* __register_global_object(void* object, void* destructor, void* chain);
extern void fn_27_22C2D0(void* self, int flags);
}

extern "C" void fn_27_22C26C(void) {
    __ct__11stClassInfoFv(lbl_27_bss_5794);
    *(void**)lbl_27_bss_5794 = lbl_27_data_4B108;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_27_bss_5794, 0x28, lbl_27_bss_5794);
    __register_global_object(lbl_27_bss_5794, fn_27_22C2D0, lbl_27_bss_5788);
}

__declspec(section ".ctors") extern void* const fn_27_22C26C_ctor = (void*)fn_27_22C26C;
