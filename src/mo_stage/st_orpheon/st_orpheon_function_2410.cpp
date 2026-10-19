#pragma force_active on
extern "C" {
extern unsigned char lbl_55_data_590[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, int, void*);
void __dt__11stClassInfoFv(void*, int);
void __dl__FPv(void*);

void* fn_55_2410(void* self, int flag) {
    if (self != 0) {
        *(void**)self = lbl_55_data_590;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 12, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
