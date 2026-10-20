#pragma force_active on
extern "C" {
int fn_27_1D0BB4(const unsigned int* data)
{
    return (int)((data[2] << 4) & 0xF8000000u) >> 28;
}
}
