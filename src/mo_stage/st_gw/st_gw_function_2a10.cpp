#pragma force_active on
extern "C" {
extern char lbl_63_data_8C0[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, int kind, void* info);
void __dt__11stClassInfoFv(void* self, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_63_2A10(void* self, int flags)
{
    if (self != 0) {
        *(void**)self = lbl_63_data_8C0;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x18, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
