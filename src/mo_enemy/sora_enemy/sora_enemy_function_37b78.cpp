#include <types.h>
#pragma force_active on

struct soraEnemyObj {
    u8 pad[0xC8];
};

extern "C" void fn_41_37B18(void* self, s16 shouldDelete);
extern "C" void fn_41_37A1C(void* self, s16 shouldDelete);

extern "C" soraEnemyObj* fn_41_37B78(soraEnemyObj* obj, s16 shouldDelete) {
    if (obj != nullptr) {
        fn_41_37B18((char*)obj + 0xC8, -1);
        fn_41_37A1C((char*)obj + 4, -1);
        if (shouldDelete > 0) {
            delete obj;
        }
    }
    return obj;
}
