#pragma force_active on
class stClassInfo;

namespace Stages {
    enum srStageKind {
        srStageKind_Dummy = 0
    };
}

extern "C" {
    extern stClassInfo* lbl_27_bss_5670[66];
}

class stClassInfo {
public:
    void setClassInfo(Stages::srStageKind kind, stClassInfo* info);
};

void stClassInfo::setClassInfo(Stages::srStageKind kind, stClassInfo* info) {
    lbl_27_bss_5670[kind] = info;
}
