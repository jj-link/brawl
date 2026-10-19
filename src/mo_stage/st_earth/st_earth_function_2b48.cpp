#pragma force_active on
extern "C" {
extern char lbl_66_data_540[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, int, void*);
void __dt__11stClassInfoFv(void*, int);
void __dl__FPv(void*);

void* fn_66_2B48(void* self, int flags) {
    if (self) {
        *(void**)self = lbl_66_data_540;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x1d, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
