typedef float f32;
struct Vec3f { f32 x, y, z; };
#include <snd/snd_3d_generator.h>
#pragma force_active on

extern "C" snd3DGenerator* fn_27_57E34(void* p1, int p2) {
    return reinterpret_cast<snd3DGenerator*>(
        *reinterpret_cast<unsigned char**>(static_cast<char*>(p1) + 4) +
        p2 * 0x14 + 0x0C
    );
}
