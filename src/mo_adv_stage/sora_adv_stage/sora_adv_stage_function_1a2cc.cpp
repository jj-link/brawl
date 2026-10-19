#include <types.h>
#pragma force_active on

class grYakumonoPunchSlider;

extern "C" {
void __dt__21grYakumonoPunchSliderFv(grYakumonoPunchSlider* self, int flags);
void __dl__FPv(void* p);

void* fn_40_1A2CC(grYakumonoPunchSlider* self, int flags)
{
    if (self != 0) {
        __dt__21grYakumonoPunchSliderFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
