#include <stddef.h>
#pragma force_active on

class grYakumonoPunchSlider {
public:
    ~grYakumonoPunchSlider();
};

extern "C" {
void __dt__21grYakumonoPunchSliderFv(grYakumonoPunchSlider* self, int flags);
void __dl__FPv(void* p);

grYakumonoPunchSlider* fn_40_25B58(grYakumonoPunchSlider* self, int shouldFree) {
    if (self != NULL) {
        __dt__21grYakumonoPunchSliderFv(self, 0);
        if (shouldFree > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
