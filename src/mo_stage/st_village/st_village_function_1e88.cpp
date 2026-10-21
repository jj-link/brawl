#pragma force_active on
extern "C" {
typedef struct { void* vtable; } stClassInfo;
void __ct__11stClassInfoFv(stClassInfo*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(stClassInfo*, int, stClassInfo*);
void* __register_global_object(void*, void*, void*);
void fn_70_1EEC();
extern stClassInfo lbl_70_bss_14;
extern unsigned char lbl_70_bss_8[];
extern void* lbl_70_data_A08[];
}

extern "C" void fn_70_1E88() {
    __ct__11stClassInfoFv(&lbl_70_bss_14);
    lbl_70_bss_14.vtable = (void*)lbl_70_data_A08;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(&lbl_70_bss_14, 0x21, &lbl_70_bss_14);
    __register_global_object(&lbl_70_bss_14, &fn_70_1EEC, lbl_70_bss_8);
}

__declspec(section ".ctors") extern void* const fn_70_1E88_ctor = (void*)fn_70_1E88;
