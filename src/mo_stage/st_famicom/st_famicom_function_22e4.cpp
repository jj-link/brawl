#pragma force_active on
typedef struct stClassInfoLike {
    void* vtbl;
} stClassInfoLike;

extern "C" {
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(stClassInfoLike* self, int kind, void* info);
void __dt__11stClassInfoFv(stClassInfoLike* self, int flags);
void __dl__FPv(void* p);
extern char lbl_68_data_538[];

stClassInfoLike* fn_68_22E4(stClassInfoLike* self, int shouldFree) {
    if (self != 0) {
        self->vtbl = lbl_68_data_538;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x1f, 0);
        __dt__11stClassInfoFv(self, 0);
        if (shouldFree > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
