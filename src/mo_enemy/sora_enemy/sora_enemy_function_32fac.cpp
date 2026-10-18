#include <types.h>
#pragma force_active on

extern "C" void* getInstance__9itManagerFv();
extern "C" u32 fn_27_2AC210(void*, u32);
extern "C" void fn_27_1DB0E8(void*, f32, void*, void*, void*, void*, void*);

extern "C" void fn_41_32FAC(u8* self, f32 f1, void* p2, void* p3, void* p4, void* p5, u8* p6) {
    u32 id = *reinterpret_cast<u32*>(p6 + 0xc);
    if (id != 0xffffffff) {
        if (fn_27_2AC210(getInstance__9itManagerFv(), id) == 1) {
            self[0x2217] = 1;
        }
    }
    fn_27_1DB0E8(self + 0xc, f1, p2, p3, p4, p5, p6);
}
