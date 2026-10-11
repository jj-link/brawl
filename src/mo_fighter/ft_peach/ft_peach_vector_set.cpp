#include <types.h>

extern "C" void fn_103_9594(void* destination, f32 x, f32 y, f32 z) {
    f32* vector = static_cast<f32*>(destination);
    vector[0] = x;
    vector[1] = y;
    vector[2] = z;
}
