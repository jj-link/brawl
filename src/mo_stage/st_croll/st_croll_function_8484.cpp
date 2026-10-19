#pragma force_active on
typedef signed int s32;

extern "C" void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, s32, void*);
extern "C" void __dt__11stClassInfoFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_90_data_2DD8[];

extern "C" {
void* fn_90_8484(void* self, s32 del) {
    if (self) {
        *(void**)self = lbl_90_data_2DD8;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x39, 0);
        __dt__11stClassInfoFv(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
