#pragma force_active on
extern "C" void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, int, void*);
extern "C" void __dt__11stClassInfoFv(void*, int);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_60_data_7D8[];

extern "C" void* fn_60_629C(void* self, int del) {
    if (self != 0) {
        *(void**)self = (void*)lbl_60_data_7D8;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x15, 0);
        __dt__11stClassInfoFv(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
