#pragma force_active on
namespace Stages {
enum srStageKind { };
}

struct stClassInfo {
    virtual ~stClassInfo();
    void setClassInfo(Stages::srStageKind kind, stClassInfo* info);
};

extern "C" {
extern void* lbl_80_data_538[];
void __dt__11stClassInfoFv(stClassInfo* self, int flag);
void __dl__FPv(void* p);
}

extern "C" stClassInfo* fn_80_2AA0(stClassInfo* self, int del) {
    if (self) {
        *(void**)self = lbl_80_data_538;
        self->setClassInfo((Stages::srStageKind)0x2f, 0);
        __dt__11stClassInfoFv(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
