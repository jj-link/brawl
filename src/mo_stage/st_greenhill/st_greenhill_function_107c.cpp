#pragma force_active on
extern "C" {
extern char lbl_72_data_4D0[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_72_107C(void* self, int flags) {
    if (self) {
        *(void**)self = lbl_72_data_4D0;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x23, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
