#include "include/lib/BrawlHeaders/Brawl/Include/so/controller/so_controller_module_impl.h"
#include "include/lib/BrawlHeaders/Brawl/Include/ac/ac_anim_cmd_impl.h"
#include "include/lib/BrawlHeaders/Brawl/Include/so/so_module_accesser.h"
#pragma force_active on

extern "C" s32 fn_27_150C00(soControllerModuleImpl* self, acAnimCmd* acmd, soModuleAccesser* accessor, s32 arg3) {
    s8 group = acmd->getGroup();
    if (self->isObserv(group) == false) {
        return 0;
    }
    if (acmd->getType() <= -1 || acmd->getType() >= 0xd) {
        return 0;
    }
    switch (acmd->getType()) {
    case 0xc:
        self->clearLog();
        return 1;
    }
    return self->soControllerModuleImpl::notifyEventAnimCmd(acmd, accessor, arg3);
}