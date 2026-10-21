#pragma force_active on
extern "C" {
extern char lbl_79_bss_14[];
extern char lbl_79_bss_8[];
extern char lbl_79_data_428[];
void fn_79_18EC(void* p);
void* __register_global_object(void* object, void* destructor, void* chain);
void __ct__11stClassInfoFv(void* self);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);

void fn_79_1888() {
    __ct__11stClassInfoFv(lbl_79_bss_14);
    *(char**)lbl_79_bss_14 = lbl_79_data_428;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_79_bss_14, 0x2d, lbl_79_bss_14);
    __register_global_object(lbl_79_bss_14, (void*)fn_79_18EC, lbl_79_bss_8);
}
}

__declspec(section ".ctors") extern void* const fn_79_1888_ctor = (void*)fn_79_1888;
