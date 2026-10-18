#include <types.h>
#pragma force_active on

extern "C" {
float fn_111_10DEC(u32* arg0)
{
    return reinterpret_cast<float*>(arg0)[2] * reinterpret_cast<float*>(arg0)[3];
}
}
