#pragma force_active on
namespace Stages {
enum srStageKind { Config = 0x15 };
}

class stClassInfo {
public:
    void setClassInfo(Stages::srStageKind kind, stClassInfo* info);
};

extern "C" {
extern stClassInfo lbl_60_bss_14;
extern char lbl_60_data_7D8[];
extern char lbl_60_bss_8[];
void __ct__11stClassInfoFv(stClassInfo* self);
void fn_60_629C(void* p);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_60_6238(void) {
    __ct__11stClassInfoFv(&lbl_60_bss_14);
    *(void**)&lbl_60_bss_14 = (void*)lbl_60_data_7D8;
    lbl_60_bss_14.setClassInfo(Stages::Config, &lbl_60_bss_14);
    __register_global_object(&lbl_60_bss_14, (void*)fn_60_629C, lbl_60_bss_8);
}
}

__declspec(section ".ctors") extern void* const fn_60_6238_ctor = (void*)fn_60_6238;
