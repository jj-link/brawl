#pragma force_active on
typedef struct {
    char pad[0x158];
    float x;
    float y;
    float z;
} Src;

extern "C" void fn_67_C8BC(Src *self, float *out)
{
    if (out == 0) return;
    out[0] = self->x;
    out[1] = self->y;
    out[2] = self->z;
}
