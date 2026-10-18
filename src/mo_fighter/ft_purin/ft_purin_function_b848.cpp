#pragma force_active on
struct FtPurinPosDst
{
    char pad[8];
    float x;
    float y;
};

extern "C" void fn_124_B848(FtPurinPosDst* dst, const float* src)
{
    dst->x = src[0];
    dst->y = src[1];
}
