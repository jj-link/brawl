#include <types.h>
#pragma force_active on

extern "C" {
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flags);
void __dl__FPv(void* p);
extern char lbl_67_data_910[];
}

extern "C" void* fn_67_1E70(void* self, int flags) {
    if (self) {
        *(char**)self = lbl_67_data_910;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x1E, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
