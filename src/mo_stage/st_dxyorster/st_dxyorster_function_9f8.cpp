#pragma force_active on
struct stClassInfo {
    void* vtbl;
};

extern "C" {
    extern char lbl_76_data_3C8[];
    void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(stClassInfo* self, int kind, stClassInfo* p);
    void __dt__11stClassInfoFv(stClassInfo* self, int flags);
    void __dl__FPv(void* p);
}

extern "C" stClassInfo* fn_76_9F8(stClassInfo* self, int del) {
    if (self) {
        self->vtbl = lbl_76_data_3C8;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x2a, 0);
        __dt__11stClassInfoFv(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
