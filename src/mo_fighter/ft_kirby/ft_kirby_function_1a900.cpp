#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/link/so_link_module_impl.h>
#include <so/link/so_link_event_presenter.h>
#pragma force_active on

namespace {
struct FnLinkEvent : soLinkEventArgs {
    int unk8;
    float unkC;

    FnLinkEvent(int eventKind) : soLinkEventArgs(eventKind) {}
};
}

extern "C" {
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
}

extern "C" void fn_96_1A900(void* process, soModuleAccesser* accesser) {
    int count = accesser->getWorkManageModule().getInt(0x20000006);
    if (accesser->getWorkManageModule().isFlag(0x22000013)) {
        accesser->getWorkManageModule().subInt(1, 0x20000010);
        if (accesser->getWorkManageModule().getInt(0x20000010) <= 0) {
            FnLinkEvent ev(0x2d);
            ev.unkC = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0x5dd2, 0);
            for (int i = 0; i < count; i++) {
                int v = accesser->getWorkManageModule().getInt(0x20000000 + i);
                if ((u32)(v + 0x10000) != 0xFFFF) {
                    accesser->getLinkModule().link(4, v);
                    accesser->getLinkModule().sendEventParents(4, ev);
                    accesser->getLinkModule().unlink(4);
                }
            }
            soWorkManageModule* workA = &accesser->getWorkManageModule();
            int value = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0x5dd1, 0);
            workA->setInt(value, 0x20000010);
        }
        accesser->getWorkManageModule().addInt(1, 0x20000011);
        soWorkManageModule* workB = &accesser->getWorkManageModule();
        int limit = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0x5dd3, 0);
        if (workB->getInt(0x20000011) >= limit) {
            accesser->getWorkManageModule().offFlag(0x22000013);
        }
    }
}
