#pragma force_active on
extern "C" void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    void*, int, void*);
extern "C" void __dt__11stClassInfoFv(void*, int);
extern "C" void __dl__FPv(void*);
extern "C" unsigned char lbl_54_data_4E0[];

extern "C" void* fn_54_2B94(void* self, int flags) {
    if (self != 0) {
        *(void**)self = lbl_54_data_4E0;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
            self, 0xB, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
