#include <st_dxbigblue/gr_dxbigblue.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);
extern "C" void __dt__11grDxBigBlueFv(grDxBigBlue*, int);

extern "C" grDxBigBlue* fn_81_4F40(grDxBigBlue* self, int shouldDelete) {
    if (self != 0) {
        __dt__11grDxBigBlueFv(self, 0);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
