#pragma force_active on
extern "C" void fn_96_1BCD8(float *out, float t, int unused, const float *start, const float *end)
{
    out[0] = start[0] + t * (end[0] - start[0]);
    out[1] = start[1] + t * (end[1] - start[1]);
    out[2] = start[2] + t * (end[2] - start[2]);
}
