#pragma force_active on
extern "C" {
extern char lbl_74_data_5E0[];
void __dl__FPv(void*);
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flags);
void* fn_74_2598(void* self, int flags);
}

void* fn_74_2598(void* self, int flags) {
    if (self) {
        *(char**)self = lbl_74_data_5E0;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x25, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
