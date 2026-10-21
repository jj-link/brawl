#pragma force_active on
namespace Stages {
enum srStageKind { srStageKind_Config = 6 };
}

class stClassInfo {
public:
    stClassInfo();
    virtual ~stClassInfo();
};

extern "C" void __ct__11stClassInfoFv(stClassInfo *self);
extern "C" void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(stClassInfo *self, Stages::srStageKind kind, stClassInfo *info);
extern "C" void *__register_global_object(void *object, void *destructor, void *chain);
extern "C" void fn_49_1224();

extern "C" char lbl_49_data_3F0[0x14];
extern "C" void *lbl_49_bss_14;
extern "C" char lbl_49_bss_8[0xC];

extern "C" void fn_49_11C0() {
    __ct__11stClassInfoFv((stClassInfo *)&lbl_49_bss_14);
    lbl_49_bss_14 = lbl_49_data_3F0;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo((stClassInfo *)&lbl_49_bss_14, Stages::srStageKind_Config, (stClassInfo *)&lbl_49_bss_14);
    __register_global_object(&lbl_49_bss_14, (void *)fn_49_1224, lbl_49_bss_8);
}

__declspec(section ".ctors") extern void* const fn_49_11C0_ctor = (void*)fn_49_11C0;
