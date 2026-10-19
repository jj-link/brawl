#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_12D904(void* self, bool arg1, bool arg2, int arg3);
void removeCallBack__15soPhotoCallBackFv(void* self);

void fn_103_99FC(void* self) {
    fn_27_12D904(self, true, true, 0);
    removeCallBack__15soPhotoCallBackFv(static_cast<u8*>(self) + 0x186F0);
}
}
