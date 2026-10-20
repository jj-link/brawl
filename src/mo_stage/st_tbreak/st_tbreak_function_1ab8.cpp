#pragma force_active on
struct stClassInfo {
    void* vtbl;
};

extern "C" {
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flags);
extern void* lbl_89_data_C80[];
}

void operator delete(void* p);

extern "C" stClassInfo* fn_89_1AB8(stClassInfo* self, int flags) {
    if (self != 0) {
        self->vtbl = lbl_89_data_C80;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x38, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
