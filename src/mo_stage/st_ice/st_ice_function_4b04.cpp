#pragma force_active on
extern float *g_soWorld;

extern "C" void fn_62_4B04(float a, float b)
{
    g_soWorld[0] = a;
    g_soWorld[1] = b;
}
