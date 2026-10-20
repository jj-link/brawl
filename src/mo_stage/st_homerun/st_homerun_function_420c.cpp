#pragma force_active on
typedef struct {
    char pad[1460];
    float f;
} S;

extern "C" void fn_88_420C(S* obj, unsigned char idx, float val)
{
    (&obj->f)[idx] = val;
}
