#pragma force_active on
extern "C" {
extern char lbl_46_data_C28[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_46_4400(void* self, int flags) {
    if (self != 0) {
        *(char**)self = lbl_46_data_C28;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 3, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
