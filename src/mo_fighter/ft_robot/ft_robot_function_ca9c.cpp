#include <types.h>
#pragma force_active on

namespace {
struct RobotElementFlags {
    unsigned char flag : 1;
    unsigned char rest : 7;
};
}

extern "C" {
void fn_120_CA4C(void*, void*);
s16* fn_120_CC1C(s16* destination, const s16* source);
void fn_120_CB2C(void*, s16*, void*);
}

extern "C" void fn_120_CA9C(void* object, const s16* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*operation & 0x8) {
        bool flag = reinterpret_cast<RobotElementFlags*>(element + 5)->flag;
        if (flag == true && element[6] == 0) {
            fn_120_CA4C(element, argument);
        }
    }
    s16 next;
    fn_120_CC1C(&next, operation);
    fn_120_CB2C(composite + 4, &next, argument);
}
