#pragma force_active on
typedef unsigned int u32;

struct stClassInfo {
    const void* vtable;
};

extern const unsigned char lbl_83_data_3A8[];

extern "C" void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
    stClassInfo*, int, stClassInfo*);
extern "C" stClassInfo* __dt__11stClassInfoFv(stClassInfo*, int);
extern "C" void __dl__FPv(void*);

extern "C" stClassInfo* fn_83_2D7C(stClassInfo* self, int shouldDelete) {
    if (self != 0) {
        self->vtable = lbl_83_data_3A8;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 46, 0);
        __dt__11stClassInfoFv(self, 0);
        if (shouldDelete > 0)
            __dl__FPv(self);
    }
    return self;
}
