#pragma force_active on
typedef int s32;

extern "C" {
extern unsigned char lbl_51_data_968[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    void*, s32, void*);
void __dt__11stClassInfoFv(void*, s32);
void __dl__FPv(void*);
void* fn_51_2784(void* ptr, s32 size);
}

extern "C" void* fn_51_2784(void* ptr, s32 size) {
    if (ptr != 0) {
        *(void**)ptr = lbl_51_data_968;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
            ptr, 8, 0);
        __dt__11stClassInfoFv(ptr, 0);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
