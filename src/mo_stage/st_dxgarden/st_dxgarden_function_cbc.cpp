#pragma force_active on
extern "C" {
void __ct__11stClassInfoFv(void*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, int, void*);
void fn_77_D20(void*, int);
void* __register_global_object(void*, void*, void*);
extern unsigned char lbl_77_data_4C0[];
extern unsigned char lbl_77_bss_14[];
extern unsigned char lbl_77_bss_8[];

void fn_77_CBC(void);
}

extern "C" void fn_77_CBC(void) {
    __ct__11stClassInfoFv(lbl_77_bss_14);
    *(void**)lbl_77_bss_14 = lbl_77_data_4C0;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_77_bss_14, 0x2b, lbl_77_bss_14);
    __register_global_object(lbl_77_bss_14, (void*)fn_77_D20, lbl_77_bss_8);
}

__declspec(section ".ctors") extern void* const fn_77_CBC_ctor = (void*)fn_77_CBC;
