#include <gf/gf_application.h>
#include <types.h>
#pragma force_active on
extern const float lbl_805A2630;
extern "C" float fn_800F5CBC() {
    float rate = (float)g_gfApplication->m_frameRate;
    if (rate < lbl_805A2630) rate = lbl_805A2630;
    return lbl_805A2630 / rate;
}
