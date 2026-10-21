#pragma force_active on
extern "C" {
extern char lbl_67_bss_14[];
extern char lbl_67_data_910[];
extern char lbl_67_bss_8[];

void __ct__11stClassInfoFv(void*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, int, void*);
void* fn_67_1E70(void*, int);
void* __register_global_object(void*, void*, void*);

void fn_67_1E0C() {
    __ct__11stClassInfoFv(lbl_67_bss_14);
    *(void**)lbl_67_bss_14 = lbl_67_data_910;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        lbl_67_bss_14, 0x1e, lbl_67_bss_14);
    __register_global_object(
        lbl_67_bss_14, (void*)fn_67_1E70, lbl_67_bss_8);
}
}

__declspec(section ".ctors") extern void* const fn_67_1E0C_ctor = (void*)fn_67_1E0C;
