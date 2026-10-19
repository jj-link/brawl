#include <st/st_class_info.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_82_data_648[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    stClassInfo*, Stages::srStageKind, stClassInfo*);
void __dt__11stClassInfoFv(stClassInfo*, int);
void __dl__FPv(void*);
}

extern "C" stClassInfo* fn_82_3F24(stClassInfo* self, int shouldDelete)
{
    if (self != 0) {
        *(void**)self = lbl_82_data_648;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
            self, Stages::Corneria, 0);
        __dt__11stClassInfoFv(self, 0);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
