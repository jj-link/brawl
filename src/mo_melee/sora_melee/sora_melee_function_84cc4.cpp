#include <types.h>
#pragma force_active on

namespace {
    struct VTableTest {
        virtual s32 v0();
        virtual s32 v1();
        virtual s32 v2();
        virtual s32 v3();
    };
}

extern "C" bool fn_27_84CC4(VTableTest* obj) {
    return obj->v3() == 0;
}
