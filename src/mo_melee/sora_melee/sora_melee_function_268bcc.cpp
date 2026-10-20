#include <types.h>
#pragma force_active on

class grYakumonoPunchSlider;

extern "C" {
void __dt__10grYakumonoFv(void* self, int flags);
void __dl__FPv(void* p);

void* __dt__21grYakumonoPunchSliderFv(grYakumonoPunchSlider* self, int flags)
{
    if (self != 0) {
        __dt__10grYakumonoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
