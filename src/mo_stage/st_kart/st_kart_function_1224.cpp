#pragma force_active on
extern "C" {
extern char lbl_49_data_3F0[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_49_1224(void* self, int flag) {
    if (self) {
        *(void**)self = lbl_49_data_3F0;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 6, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
