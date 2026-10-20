#pragma force_active on
struct FrameData
{
    unsigned char unknown[8];
};

extern "C" void* fn_27_D9278(FrameData* p, int index)
{
    int frame = ((int*)p)[2] >> 25;
    int sum = frame + index;
    if (sum >= 0x34)
        sum -= 0x34;
    return (char*)p + sum * 0x30 + 0xC;
}
