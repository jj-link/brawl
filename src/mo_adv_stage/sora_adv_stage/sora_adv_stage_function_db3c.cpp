#pragma force_active on
extern "C" {
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    void*, int, void*);
void __dt__11stClassInfoFv(void*, int);
void __dl__FPv(void*);
extern unsigned char lbl_40_data_1894[];
}

extern "C" void* fn_40_DB3C(void* self, int flags) {
    if (self != 0) {
        *(void**)self = lbl_40_data_1894;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
            self, 0x3D, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
