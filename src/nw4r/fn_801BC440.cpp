#pragma force_active on
typedef struct {
    char pad[56];
    float f;
} S;

extern "C" void fn_801BC440(S* obj, unsigned int idx, float val)
{
    (&obj->f)[idx] = val;
}
