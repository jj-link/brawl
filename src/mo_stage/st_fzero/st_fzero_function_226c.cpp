#pragma force_active on
extern char lbl_61_data_AB8[];

extern "C" {
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flags);
void __dl__FPv(void* p);

void* fn_61_226C(void* self, int flags) {
    if (self != 0) {
        *(void**)self = lbl_61_data_AB8;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x16, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
