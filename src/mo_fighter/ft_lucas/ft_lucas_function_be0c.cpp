#include <StaticAssert.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_27_361264(void* object);
extern "C" void fn_27_361274(void* object, int destroy);
extern "C" void __register_global_object(void* object, void (*destructor)(int), void* storage);

extern "C" s8 lbl_114_bss_1C4;
extern "C" u8 lbl_114_bss_1C8[8];
extern "C" u8 lbl_114_bss_1B0[0xC];

extern "C" void* fn_114_BE0C() {
    if (!(signed char)lbl_114_bss_1C4) {
        fn_27_361264(lbl_114_bss_1C8);
        __register_global_object(lbl_114_bss_1C8, reinterpret_cast<void (*)(int)>(fn_27_361274), lbl_114_bss_1B0);
        lbl_114_bss_1C4 = 1;
    }
    return lbl_114_bss_1C8;
}
