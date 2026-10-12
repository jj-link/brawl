#include <types.h>

class soModuleAccesser;

extern "C" void fn_98_E554(int kind, void* state, soModuleAccesser* accesser);
extern "C" void fn_27_BEB00(void* energy);
extern "C" void* fn_98_E158(void* pool, int index);
extern "C" void* fn_98_DEBC(void* pool, int index);
extern "C" void* fn_98_DC20(void* pool, int index);
extern "C" void* fn_98_D984(void* pool, int index);
extern "C" void* fn_98_D6E8(void* pool, int index);
extern "C" void* fn_98_D44C(void* pool, int index);
extern "C" void* fn_98_D1B4(void* pool, int index);
extern "C" void* fn_98_CF18(void* pool, int index);

extern "C" void fn_98_C558(void* mediator, int kind, soModuleAccesser* accesser) {
    u8* pools = static_cast<u8*>(mediator);
    fn_98_E554(kind, pools + 4, accesser);
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_98_E158(pools + 0x208, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_98_DEBC(pools + 0x1cc, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_98_DC20(pools + 0x180, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_98_D984(pools + 0x138, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_98_D6E8(pools + 0xf0, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_98_D44C(pools + 0x98, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_98_D1B4(pools + 0x64, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_98_CF18(pools + 8, i));
    }
}
