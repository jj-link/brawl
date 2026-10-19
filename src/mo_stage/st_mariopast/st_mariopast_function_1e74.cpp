#pragma force_active on
extern "C" {
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, int, void*);
void __dt__11stClassInfoFv(void*, int);
void __dl__FPv(void*);
extern unsigned char lbl_48_data_4C8[];
}

extern "C" void* fn_48_1E74(void* self, int flags) {
    if (self != 0) {
        *(void**)self = lbl_48_data_4C8;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 5, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
