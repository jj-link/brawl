#pragma force_active on
namespace Stages {
enum srStageKind { srStageKind_Dummy = 0 };
}

class stClassInfo {
public:
    void setClassInfo(Stages::srStageKind kind, stClassInfo* info);
};

extern "C" char lbl_65_data_7E0[];
extern "C" void __dl__FPv(void*);
extern "C" void __dt__11stClassInfoFv(stClassInfo* self, short flag);

extern "C" {
stClassInfo* fn_65_6A78(stClassInfo* self, int del) {
    if (self != 0) {
        *(void**)self = (void*)lbl_65_data_7E0;
        self->setClassInfo((Stages::srStageKind)0x1c, 0);
        __dt__11stClassInfoFv(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
