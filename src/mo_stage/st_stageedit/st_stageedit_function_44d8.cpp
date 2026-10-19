#pragma force_active on
struct StageEdit {
    unsigned char pad[0x29c];
    float x;
    float y;
    float z;
};

extern "C" void fn_85_44D8(StageEdit *src, float *dst)
{
    dst[0] = src->x;
    dst[1] = src->y;
    dst[2] = src->z;
}
