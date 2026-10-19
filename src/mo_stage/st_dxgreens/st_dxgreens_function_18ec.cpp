#pragma force_active on
extern "C" void __dl__FPv(void*);

class stClassInfo {
public:
    virtual ~stClassInfo();
    void setClassInfo(int kind, stClassInfo* info);
};

extern char lbl_79_data_428[];

extern "C" void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(stClassInfo*, int, stClassInfo*);
extern "C" void __dt__11stClassInfoFv(stClassInfo*, int);

extern "C" {
stClassInfo* fn_79_18EC(stClassInfo* self, int flag) {
    if (self != 0) {
        *(char**)self = lbl_79_data_428;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(self, 0x2d, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
