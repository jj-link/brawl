#include <types.h>
#pragma force_active on

extern "C" void* fn_114_19B2C(void* object, int index);
extern "C" int fn_27_8D3E4(void* object);

extern "C" void fn_114_19A50(void* object) {
    for (int index = 0; index < 6; ++index) {
        void* member = fn_114_19B2C(static_cast<char*>(object) + 0x0c, index);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
}
