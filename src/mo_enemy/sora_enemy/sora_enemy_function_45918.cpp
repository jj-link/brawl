#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern char __RTTI__18soEffectModuleImpl[];
extern char __RTTI__14soEffectModule[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
extern float lbl_41_rodata_FC0;
extern float lbl_41_rodata_FC4;

extern "C" void fn_41_45918(wnemSimple* wn, soModuleAccesser* acc) {
    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        wnemCommonProc::Report("call wnemBosspackunProc::ArmEnter  \n");
        wn->setProcFnc_HpZero(0x11);
        s32* data = wn->unk2234;
        if (data) {
            wn->unk21E8 = data[4];
            wn->unk21EC = data[5];
            soEffectModuleImpl* effect = static_cast<soEffectModuleImpl*>(__dynamic_cast(
                &acc->getEffectModule(), 0, __RTTI__18soEffectModuleImpl, __RTTI__14soEffectModule, 1));
            effect->unk50 = data[6];
        }
        if (*reinterpret_cast<s32*>(reinterpret_cast<char*>(wn) + 0x21cc) == 0) {
            acc->getPostureModule().setLr(lbl_41_rodata_FC0);
        } else {
            acc->getPostureModule().setLr(lbl_41_rodata_FC4);
        }
    }
    wn->changeProcFnc(0x10, 1);
}