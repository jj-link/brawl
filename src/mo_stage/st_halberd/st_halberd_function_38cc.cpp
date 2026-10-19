#pragma force_active on
struct stClassInfo;

extern "C" {
extern char lbl_57_data_560[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(stClassInfo* self, int kind, stClassInfo* info);
void __dt__11stClassInfoFv(stClassInfo* self, int flags);
void __dl__FPv(void* p);
}

extern "C" stClassInfo* fn_57_38CC(stClassInfo* self, int flags) {
    if (self) {
        *(void**)self = lbl_57_data_560;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 14, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
