#pragma force_active on
namespace Stages {
enum srStageKind { srStageKind_Dummy = 0 };
}

class stClassInfo {
public:
    void setClassInfo(Stages::srStageKind kind, stClassInfo* info);
};

extern "C" void __ct__11stClassInfoFv(void* p);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);
extern "C" void fn_81_40CC(void* obj, short flag);

extern "C" char lbl_81_bss_14[];
extern "C" char lbl_81_bss_8[];
extern "C" char lbl_81_data_740[];

extern "C" {
void fn_81_4068()
{
    __ct__11stClassInfoFv(lbl_81_bss_14);
    *(void**)lbl_81_bss_14 = (void*)lbl_81_data_740;
    ((stClassInfo*)lbl_81_bss_14)->setClassInfo((Stages::srStageKind)0x31, (stClassInfo*)lbl_81_bss_14);
    __register_global_object(lbl_81_bss_14, (void*)fn_81_40CC, lbl_81_bss_8);
}
}

__declspec(section ".ctors") extern void* const fn_81_4068_ctor = (void*)fn_81_4068;
