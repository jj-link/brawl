#include <st/st_class_info.h>
#pragma force_active on

extern "C" char lbl_42_data_358[];

extern "C" void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    stClassInfo*, Stages::srStageKind, stClassInfo*);
extern "C" void __dt__11stClassInfoFv(stClassInfo*, int);
extern "C" void __dl__FPv(void*);

extern "C" stClassInfo* fn_42_544(stClassInfo* self, int flag) {
    if (self) {
        *(void**)self = lbl_42_data_358;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
            self, Stages::srStageKind(0x41), 0);
        __dt__11stClassInfoFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
