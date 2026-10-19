#pragma force_active on
extern "C" {
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flags);
void __dl__FPv(void* p);
extern char lbl_47_data_5D0[];
}

struct stClassInfoObj {
    void* vtbl;
};

extern "C" stClassInfoObj* fn_47_15C4(stClassInfoObj* self, int flags) {
    if (self != 0) {
        self->vtbl = lbl_47_data_5D0;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 4, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
