#include <cstddef>
#pragma force_active on

struct Ftpoke { };

extern "C" {
    void fn_116_1ADC(Ftpoke*, short);

    Ftpoke* fn_116_1A80(Ftpoke* self, short param) {
        if (self != NULL) {
            fn_116_1ADC(self, 0);
            if (param > 0) {
                delete self;
            }
        }
        return self;
    }
}
