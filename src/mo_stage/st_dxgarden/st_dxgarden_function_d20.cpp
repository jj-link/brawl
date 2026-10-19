#pragma force_active on
struct stClassInfo;

extern "C" {
extern char lbl_77_data_4C0[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(stClassInfo* self, int kind, int arg);
void __dt__11stClassInfoFv(stClassInfo* self, int flags);
void __dl__FPv(void* p);
}

extern "C" stClassInfo* fn_77_D20(stClassInfo* self, int freeFlag) {
    if (self) {
        *(void**)self = (void*)lbl_77_data_4C0;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x2b, 0);
        __dt__11stClassInfoFv(self, 0);
        if (freeFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
