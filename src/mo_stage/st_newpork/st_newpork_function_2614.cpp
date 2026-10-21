#pragma force_active on
typedef int s32;

extern "C" {
extern unsigned char lbl_69_data_610[];
extern unsigned char lbl_69_bss_14[];
extern unsigned char lbl_69_bss_8[];

void __ct__11stClassInfoFv(void*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, s32, void*);
void* __register_global_object(void*, void*, void*);
void* fn_69_2678(void*, s32);

void fn_69_2614(void);
}

extern "C" void fn_69_2614(void) {
    __ct__11stClassInfoFv(lbl_69_bss_14);
    *(void**)lbl_69_bss_14 = lbl_69_data_610;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_69_bss_14, 0x20, lbl_69_bss_14);
    __register_global_object(lbl_69_bss_14, (void*)fn_69_2678, lbl_69_bss_8);
}

__declspec(section ".ctors") extern void* const fn_69_2614_ctor = (void*)fn_69_2614;
