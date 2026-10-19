#pragma force_active on
extern "C" {
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flags);
void __dl__FPv(void* p);
extern char lbl_59_data_5D0[];

void* fn_59_35D8(void* self, int flags) {
    if (self) {
        *(char**)self = lbl_59_data_5D0;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x14, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
