#pragma force_active on
namespace Stages {
enum srStageKind { srStageKind_Dummy = 0x32 };
}

class stClassInfo {
public:
    virtual ~stClassInfo();
    void setClassInfo(Stages::srStageKind kind, stClassInfo* info);
};

void operator delete(void* p);

extern "C" {
extern char lbl_84_data_4B8[];
void __dt__11stClassInfoFv(stClassInfo* self, short flag);

stClassInfo* fn_84_3F50(stClassInfo* self, int flag) {
    if (self != 0) {
        *(void**)self = (void*)lbl_84_data_4B8;
        self->setClassInfo((Stages::srStageKind)0x32, 0);
        __dt__11stClassInfoFv(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
