#pragma force_active on

extern float *g_soWorld;

// .rodata float constant shared with other translation units (lbl_27_rodata_3934)
extern "C" const float lbl_27_rodata_3934;

extern "C" void setGravityNormal__7stMeleeFv()
{
    float gravity = lbl_27_rodata_3934;
    g_soWorld[0] = gravity;
    g_soWorld[1] = gravity;
}
