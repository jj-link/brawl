#include <types.h>
#pragma force_active on

struct stClassInfo;

extern "C" {
extern void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    stClassInfo*, int, stClassInfo*);
extern void __dt__11stClassInfoFv(stClassInfo*, int);
extern void __dl__FPv(void*);
extern unsigned char lbl_78_data_4E8[];
}

extern "C" void* fn_78_15D8(void* ptr, int deleting) {
    if (ptr != 0) {
        *(void**)ptr = lbl_78_data_4E8;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
            (stClassInfo*)ptr, 0x2C, 0);
        __dt__11stClassInfoFv((stClassInfo*)ptr, 0);
        if (deleting > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
