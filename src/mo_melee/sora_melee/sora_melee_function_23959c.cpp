#include <st/st_melee.h>
#pragma force_active on

void stMelee::zoomInCamera()
{
    void* camera = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x78);
    if (camera == 0)
        return;

    float* zoom = reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x1D0);
    float* target = reinterpret_cast<float*>(reinterpret_cast<char*>(camera) + 0x10);
    target[0] = zoom[0];
    target[1] = zoom[1];
}
