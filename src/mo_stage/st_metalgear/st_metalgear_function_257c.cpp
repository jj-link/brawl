#pragma force_active on
extern "C" {
extern char lbl_71_data_6F8[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flags);
}

extern "C" void* fn_71_257C(void* self, int flags) {
    if (self) {
        *(void**)self = lbl_71_data_6F8;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x22, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
