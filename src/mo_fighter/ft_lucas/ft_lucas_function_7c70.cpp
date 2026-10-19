#include <types.h>
#pragma force_active on

struct LucasStorageObject {
    u8 base[0x178];
    u32 storage;
};

extern "C" void fn_27_6A3D8(void* storageBase, s16 flag);
extern "C" void fn_27_199F7C(LucasStorageObject* object, s16 flag);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_114_7C70(LucasStorageObject* object, s16 deleteMode) {
    if (object != nullptr) {
        fn_27_6A3D8(reinterpret_cast<u8*>(object) + 0x178, -1);
        fn_27_199F7C(object, -1);
        if (deleteMode > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
