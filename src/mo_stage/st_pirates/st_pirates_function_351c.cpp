#pragma force_active on
struct stClassInfo;

extern "C" {
extern char lbl_52_data_7E8[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_52_351C(void* self, int flags) {
    if (self != 0) {
        *(void**)self = (void*)lbl_52_data_7E8;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 9, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
