#include <so/controller/so_controller_impl.h>
#pragma force_active on

extern "C" unsigned int getButtonMask__12soControllerFQ212soController9PadButton(int);

extern "C" int fn_27_5AD04(soController* self) {
    u32 mask = getButtonMask__12soControllerFQ212soController9PadButton(0) |
               getButtonMask__12soControllerFQ212soController9PadButton(1) |
               getButtonMask__12soControllerFQ212soController9PadButton(2) |
               getButtonMask__12soControllerFQ212soController9PadButton(3);
    int btn = self->getTrigger();
    return (btn & mask) != 0;
}
