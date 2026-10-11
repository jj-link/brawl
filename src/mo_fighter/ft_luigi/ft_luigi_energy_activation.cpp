#include <types.h>

class soModuleAccesser;
extern "C" void fn_99_BBD0(int kind, int resetState, soModuleAccesser* accesser);
extern "C" void fn_27_BEB00(void* energy);
extern "C" void* fn_99_B7C4(void* array, int index);
extern "C" void* fn_99_B6DC(void* array, int index);
extern "C" void* fn_99_B5F4(void* array, int index);
extern "C" void* fn_99_B50C(void* array, int index);
extern "C" void* fn_99_B424(void* array, int index);
extern "C" void* fn_99_B374(void* array, int index);
extern "C" void* fn_99_B28C(void* array, int index);
extern "C" void* fn_99_B1DC(void* array, int index);

extern "C" void fn_99_AB6C(void* object, int kind, soModuleAccesser* accesser) {
    u8* state = static_cast<u8*>(object);
    // The dispatcher's existing 32-bit argument carries the embedded state address.
    fn_99_BBD0(kind, reinterpret_cast<int>(state + 4), accesser);
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_99_B7C4(state + 0x208, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_99_B6DC(state + 0x1CC, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_99_B5F4(state + 0x180, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_99_B50C(state + 0x138, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_99_B424(state + 0xF0, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_99_B374(state + 0x98, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_99_B28C(state + 0x64, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_99_B1DC(state + 8, i));
    }
}
