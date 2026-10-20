#pragma force_active on
extern "C" {
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    void*, int, void*);
void __dt__11stClassInfoFv(void*, int);
void __dl__FPv(void*);
extern unsigned char lbl_73_data_BA0[];
}

extern "C" void* fn_73_2BB0(void* self, int flags) {
    if (self != 0) {
        *(void**)self = lbl_73_data_BA0;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
            self, 0x24, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
