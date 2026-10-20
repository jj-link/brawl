#include <types.h>
#pragma force_active on

extern "C" {
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flags);
void __dl__FPv(void* p);
extern char lbl_27_data_4B108[];

void* fn_27_22C2D0(void* self, int flags) {
    if (self) {
        *(void**)self = lbl_27_data_4B108;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x28, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
