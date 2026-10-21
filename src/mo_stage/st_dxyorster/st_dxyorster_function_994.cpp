#pragma force_active on
struct stClassInfo {
    void* vtbl;
};

extern "C" {
extern stClassInfo lbl_76_bss_14;
extern char lbl_76_data_3C8[];
extern char lbl_76_bss_8[];

void __ct__11stClassInfoFv(stClassInfo*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    stClassInfo*, int, stClassInfo*);
stClassInfo* fn_76_9F8(stClassInfo*, int);
void* __register_global_object(void*, void*, void*);

void fn_76_994() {
    __ct__11stClassInfoFv(&lbl_76_bss_14);
    lbl_76_bss_14.vtbl = lbl_76_data_3C8;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        &lbl_76_bss_14, 0x2A, &lbl_76_bss_14);
    __register_global_object(
        &lbl_76_bss_14, (void*)fn_76_9F8, lbl_76_bss_8);
}
}

__declspec(section ".ctors") extern void* const fn_76_994_ctor = (void*)fn_76_994;
