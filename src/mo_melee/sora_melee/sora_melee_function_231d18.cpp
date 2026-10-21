#pragma force_active on
extern "C" {
void __ct__11stClassInfoFv(void* self);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void fn_27_231D7C(void* self, int flags);
void* __register_global_object(void* object, void* destructor, void* chain);
extern unsigned char lbl_27_data_4B880[];
extern char lbl_27_bss_5798[];
extern char lbl_27_bss_57A4[];
}

extern "C" void fn_27_231D18() {
    char* obj = lbl_27_bss_57A4;
    __ct__11stClassInfoFv(obj);
    *(void**)obj = lbl_27_data_4B880;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(obj, 0x35, obj);
    __register_global_object(obj, fn_27_231D7C, lbl_27_bss_5798);
}

__declspec(section ".ctors") extern void* const fn_27_231D18_ctor = (void*)fn_27_231D18;
