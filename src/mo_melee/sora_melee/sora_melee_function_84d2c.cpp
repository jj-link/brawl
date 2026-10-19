#include <types.h>
#pragma force_active on

namespace {
    class Arr {
    public:
        virtual s32 f0();
        virtual s32 f1();
        virtual s32 f2();
        virtual s32 f3();
        virtual u32 size();
    };
}

extern "C" u32 fn_27_84D2C(Arr* a) {
    u32 result = a->size();
    return result == 0;
}
