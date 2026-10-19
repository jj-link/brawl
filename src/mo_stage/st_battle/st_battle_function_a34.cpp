#pragma force_active on
extern "C" {
extern char lbl_43_data_4E0[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_43_A34(void* self, int flags) {
    if (self) {
        *(void**)self = lbl_43_data_4E0;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 1, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
