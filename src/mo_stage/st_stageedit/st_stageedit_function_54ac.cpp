#pragma force_active on
extern "C" {
extern char lbl_85_data_718[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flags);
void __dl__FPv(void* p);

void* fn_85_54AC(void* self, int flags) {
    if (self != 0) {
        *(char**)self = lbl_85_data_718;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x35, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
