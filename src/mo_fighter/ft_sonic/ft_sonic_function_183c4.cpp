#pragma force_active on
extern "C" int fn_123_183C4(float f)
{
    union {
        float f;
        unsigned int i;
    } u;
    u.f = f;
    int result = 1;
    if (((u.i >> 23) & 0xFF) == 0xFF) {
        result = 0;
    }
    return result;
}
