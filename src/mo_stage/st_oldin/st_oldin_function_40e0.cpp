#pragma force_active on
typedef int s32;

extern "C" {
extern unsigned char lbl_53_data_660[];

void* fn_53_40E0(void* ptr, s32 size);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    void*, s32, void*);
void __dt__11stClassInfoFv(void*, s32);
void __dl__FPv(void*);
}

extern "C" void* fn_53_40E0(void* ptr, s32 size) {
    if (ptr != 0) {
        *(void**)ptr = lbl_53_data_660;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
            ptr, 0x33, 0);
        __dt__11stClassInfoFv(ptr, 0);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
