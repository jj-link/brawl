#include <so/work/so_general_work_simple.h>
#pragma force_active on

// Set a float work entry: the float array pointer lives at +0x14 (same layout
// as soGeneralWorkSimple); no size check, so index is used directly.
extern "C" void fn_97_B3D0(soGeneralWorkSimple* work, u32 index, float value) {
    float* floats = *reinterpret_cast<float**>(reinterpret_cast<u8*>(work) + 0x14);
    floats[index] = value;
}
