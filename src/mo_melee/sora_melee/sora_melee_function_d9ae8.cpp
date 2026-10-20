#pragma force_active on
typedef struct Self {
    int pad[2];
    int f8;
} Self;

extern "C" char* fn_27_D9AE8(Self* self, int idx)
{
    int i = (self->f8 >> 27) + idx;
    if (i >= 13) {
        i -= 13;
    }
    return (char*)self + i * 36 + 12;
}
