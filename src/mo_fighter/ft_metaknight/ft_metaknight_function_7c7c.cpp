#include <so/so_module_accesser.h>
#include <ft/fighter.h>
#pragma force_active on

extern "C" void fn_27_131CD0(void* object, SituationKind kind, SituationKind previous,
                              soModuleAccesser* accesser);

// The virtual calls below are picked by the vtable slot the original uses.
// The method names are unverified; only the generated code was checked.
extern "C" void fn_111_7C7C(void* object, SituationKind kind, SituationKind previous,
                            soModuleAccesser* accesser) {
    if (kind != 2) {
        accesser->getWorkManageModule().offFlag(0x1200003D);
    }
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x9B:
        if (kind == 0) {
            accesser->getVisibilityModule().setStatusDefault(2, 0, true);
        } else if (kind == 2) {
            accesser->getVisibilityModule().setStatusDefault(2, 1, true);
        }
        break;
    }
    fn_27_131CD0(object, kind, previous, accesser);
}
