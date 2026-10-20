#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_96_2D8B4(void*, soModuleAccesser*);

extern "C" void fn_96_2D558(void* self, soModuleAccesser* accesser)
{
    switch (accesser->getStatusModule().getStatusKind()) {
    case 1:
    case 2:
    case 3:
    case 4:
        fn_96_2D8B4(self, accesser);
        break;
    }
}
